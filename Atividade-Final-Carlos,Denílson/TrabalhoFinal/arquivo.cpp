#include <iostream>
#include <fstream>
#include "bibArquivo.h"
#include "bibTADListaP.h"
#include "bibArvoreP.h"

using namespace std;

//Biblioteca responsável por realizar a leitura e preenchimento de dados em arquivo.

TFilaP intercambioF(TListaP lp,TFilaP &fp){//função responsável por realizar o intercâmbio de dados entre uma lista e uma fila.

    //instanciação das estruturas usadas
    TListaP copia;
    criarFilaPVazia(fp);
    TCelula *celAux;
    TCelula *maior;
    criarListaPVazia(copia);

    celAux = lp.primeiro->proximo;
    while(celAux != NULL){//insere os dados da lista em outra vazia, criando assim uma copia.
        inserir(copia,celAux->item);
        celAux=celAux->proximo;
    }

    do{//ordenando do maior para o menor e colocando em uma fila.
    celAux = copia.primeiro->proximo;
    while (celAux != NULL){//percorre a lista.
        if(celAux==copia.primeiro->proximo){//primeiro item da lista
            maior=celAux;//atribui valor a célula
        }
        else{
            if(maior->item.situacao.prioridade<celAux->item.situacao.prioridade){//compara o item "prioridade"
                maior=celAux;//pega o maior item.
            }
        }
        celAux = celAux->proximo;
    }
    enfileirar(fp,maior->item);//preenche a fila
    retirarPorChave(copia,maior->item);//retira o maior item da lista.

    }while(copia.contItens != 0);//este processo se repete até que a lista estaja vazia.

    return fp;//retorta a lista de prioridade do maior para o menor
}

void intercambioA(TListaP lp, TArvoreBin &a){//responsável por intercambiar os dados de uma lista e inseri-los em uma árvore de busca.

    criarArvoreBinVazia(a,"arvoreP");//cria uma árvore vazia.

    TCelula *celAux;
    celAux = lp.primeiro->proximo;

        while (celAux != NULL){//inserção de dados na árvore de busca.
            inserirA(a,a.raiz,celAux->item);
            celAux = celAux->proximo;
        }
}

TListaP lendoArqPA(string nomeArq, int quantTokens,TArvoreBin &a){//lê os dados do arquivo "pacientes" e envia-os para o intercambio entre a lista e a árvore.

    fstream arq("pacientes.txt");// instanciando e abrindo o arquivo

    TPaciente p;
    TListaP lp;
    criarListaPVazia(lp);

    if (arq.is_open()){
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken, contRegistro;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
                token = ""; // LIMPA INICIAL

                for (j=0; j < quantTokens;j++){ // LIMPA TODAS AS POSIÇÕES DO VETOR
                    valores[j] = token;
                }
                i=0;
                contToken=0;
                while (i <= int(registro.length())){  // PERCORRENDO O VETOR DE CHAR (REGISTRO)
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  PREENCHE A VARIÁVEL TOKEN
                    }
                    else{
                       valores[contToken] = token;  // PREENCHE E ARMAZENA NA POSIÇÃO CERTA
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA
                    }
                    i++;
                }
                valores[contToken] = token; // para a última palavra/TOKEN, que não tem ; no final
                for (j=0; j<quantTokens;j++){
                    if (j==1){
                        p.nomeP=valores[j];
                    }
                    else{
                        if (j==8){
                           p.idade=valores[j];
                        }
                        else{
                            if (j==2){
                               p.cpf=valores[j];
                            }
                            else{
                                if (j==3){
                                   p.numero=valores[j];
                                }
                                else{
                                    if (j==4){
                                       p.situacao.tipoSang=valores[j];
                                    }
                                    else{
                                        if (j==5){
                                            p.situacao.tempo=valores[j];
                                        }
                                        else{
                                            if (j==6){
                                                p.situacao.gravidade=valores[j];
                                            }
                                            else{
                                                if (j==7){
                                                    p.situacao.prioridade=valores[j];
                                                }
                                                else{
                                                    if (j==0){
                                                        p.situacao.receber=valores[j];
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                inserir(lp,p);//insere os itens na lista
                contRegistro++;
            }
        }
        intercambioA(lp,a);//envia a lista para o intercâmbio de dados.
    }
    arq.close();
    return lp;
}

TListaP lendoArqPF(string nomeArq, int quantTokens,TFilaP &fp){//lê os dados do arquivo "pacientes" e envia-os para o intercambio entre a lista e a fila.

    fstream arq("pacientes.txt");// instanciando e abrindo o arquivo

    TPaciente p;
    TListaP lp;
    criarListaPVazia(lp);

    if (arq.is_open()){
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken, contRegistro;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
                token = ""; // LIMPA INICIAL

                for (j=0; j < quantTokens;j++){ // LIMPA TODAS AS POSIÇÕES DO VETOR
                    valores[j] = token;
                }
                i=0;
                contToken=0;
                while (i <= int(registro.length())){  // PERCORRENDO O VETOR DE CHAR (REGISTRO)
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  PREENCHE A VARIÁVEL TOKEN
                    }
                    else{
                       valores[contToken] = token;  // PREENCHE E ARMAZENA NA POSIÇÃO CERTA
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA
                    }
                    i++;
                }
                valores[contToken] = token; // para a última palavra/TOKEN, que não tem ; no final
                for (j=0; j<quantTokens;j++){
                    if (j==1){
                        p.nomeP=valores[j];
                    }
                    else{
                        if (j==8){
                           p.idade=valores[j];
                        }
                        else{
                            if (j==2){
                               p.cpf=valores[j];
                            }
                            else{
                                if (j==3){
                                   p.numero=valores[j];
                                }
                                else{
                                    if (j==4){
                                       p.situacao.tipoSang=valores[j];
                                    }
                                    else{
                                        if (j==5){
                                            p.situacao.tempo=valores[j];
                                        }
                                        else{
                                            if (j==6){
                                                p.situacao.gravidade=valores[j];
                                            }
                                            else{
                                                if (j==7){
                                                    p.situacao.prioridade=valores[j];
                                                }
                                                else{
                                                    if (j==0){
                                                        p.situacao.receber=valores[j];
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                inserir(lp,p);
                contRegistro++;
            }
        }
        intercambioF(lp,fp);//envia os dados para o intercambio entre a lista e a fila.
    }
    arq.close();
    return lp;
}

TListaPO lendoArqO(string nomeArq, int quantTokens){//responsável por ler e retorar uma lista de órgãos

    fstream arq("orgaos.txt");// instanciando e abrindo o arquivo

    TOrgao o;
    TListaPO lpo;
    criarListaPOVazia(lpo);

    if (arq.is_open()){
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken, contRegistro;

        contRegistro = 1;
        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
                token = ""; // LIMPA INICIAL

                for (j=0; j < quantTokens;j++){ // LIMPA TODAS AS POSIÇÕES DO VETOR
                    valores[j] = token;
                }
                i=0;
                contToken=0;
                while (i <= int(registro.length())){  // PERCORRENDO O VETOR DE CHAR (REGISTRO)
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  PREENCHE A VARIÁVEL TOKEN
                    }
                    else{
                       valores[contToken] = token;  // PREENCHE E ARMAZENA NA POSIÇÃO CERTA
                                                    // para as 2 primeiras palavras
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA
                    }
                    i++;
                }
                valores[contToken] = token; // para a última palavra/TOKEN, que não tem ; no final
                for (j=0; j<quantTokens;j++){
                    if (j==2){
                       o.nomeD=valores[j];
                    }
                    else{
                        if (j==0){
                           o.nomeO=valores[j];
                        }
                        else{
                            if (j==1){
                               o.tipo=valores[j];
                            }
                        }
                    }
                }
                inserirO(lpo,o);
                contRegistro++;
            }
        }
    }
    arq.close();
    return lpo;
}

int escrevendoArqP(string nomeArq, string vetDados[], int quantTokens){//armazena as informações de um paciente em um arquivo txt.

    int i;
    string registro = "";
    fstream arquivo("pacientes.txt",ios::ate|ios::in|ios::out);

    if (arquivo.is_open()){
        for (i=0; i<quantTokens;i++){
            if (i < quantTokens-1){
                registro = registro + vetDados[i] + ";";
            }
            else{
                registro = registro + vetDados[i] + "\n";
            }
        }
        arquivo << registro;
        cout << "Dados inseridos com sucesso!" << endl;
        arquivo.close();
        return 0;
    }

    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}

int escrevendoArqO(string nomeArq, string vetDados[], int quantTokens){//armazena as informações de um órgão em um arquivo txt.

    int i;
    string registro = "";
    fstream arquivo("orgaos.txt",ios::ate|ios::in|ios::out);

    if (arquivo.is_open()){
        for (i=0; i<quantTokens;i++){
            if (i < quantTokens-1){
                registro = registro + vetDados[i] + ";";
            }
            else{
                registro = registro + vetDados[i] + "\n";
            }
        }
        arquivo << registro;
        arquivo.close();
        cout << "Dados inseridos com sucesso!" << endl;
        return 0;
    }
    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}

int escrevendoArqPC(TListaP lp){//quando esta função é chamada, o arquivo de texto "pacientes" é reescrito com as alterações feitas.
    ofstream outfile;
    string registro = "";
    fstream arquivo("pacientes.txt",ios::in|ios::out);
    TCelula *p = lp.primeiro->proximo;
    outfile.open("pacientes.txt");//limpa o arquivo.

    if (arquivo.is_open()){
        while(p != NULL){//reescreve a lista de pacientes.
            registro =p->item.situacao.receber+";"+p->item.nomeP+";"+p->item.cpf+";"+p->item.numero+";"+p->item.situacao.tipoSang+";"
            +p->item.situacao.tempo+";"+p->item.situacao.gravidade+";"+p->item.situacao.prioridade+";"+p->item.idade+"\n";
            p = p->proximo;
            arquivo << registro;
            registro = "";
        }
        arquivo.close();
        cout<<" "<<endl;
        cout << "Transplante realizado com sucesso!" << endl;
        return 0;
    }
    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}

int escrevendoArqOR(TListaPO lpo){//quando esta função é chamada, o arquivo de texto "orgaos" é reescrito com as alterações feitas.
    ofstream outfile;
    string registro = "";
    fstream arquivo("orgaos.txt",ios::in|ios::out);
    TCelulaO *p = lpo.primeiro->proximo;
    outfile.open("orgaos.txt");//limpa o arquivo.

    if (arquivo.is_open()){
        while(p != NULL){//reescreve a lista de órgãos.
            registro = p->item.nomeO+";"+p->item.tipo+";"+p->item.nomeD+"\n";
            p = p->proximo;
            arquivo << registro;
            registro = "";
        }
        arquivo.close();
        cout << "Dados inseridos com sucesso!" << endl;
        return 0;
    }
    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}
