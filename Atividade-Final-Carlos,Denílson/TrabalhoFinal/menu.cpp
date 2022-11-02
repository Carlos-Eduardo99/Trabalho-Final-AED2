#include <iostream>
#include "bibMenu.h"
#include "bibArquivo.h"
#include <sstream>
#include <fstream>
#include <windows.h>
#include "bibArvoreP.h"
#include "bibTADListaP.h"

using namespace std;

void tabela(TListaPO lpo){//responsável por comparar e retornar uma tabela de banco de órgãos.

    int tab[5][4];

    for(int i=0; i<5; i++){//inicializa a matriz com 0.
        for(int j=0;j<4;j++){
            tab[i][j] = 0;
        }
    }

    TCelulaO *celAux;
    celAux = lpo.primeiro->proximo;

        while (celAux != NULL){//compara todos os casos e preenche a matriz com os dados.
            if (celAux->item.nomeO=="1"){
                if(celAux->item.tipo == "1") tab[0][0]++;
                if(celAux->item.tipo == "2") tab[0][1]++;
                if(celAux->item.tipo == "3") tab[0][2]++;
                if(celAux->item.tipo == "4") tab[0][3]++;
            }else if(celAux->item.nomeO=="2"){
                if(celAux->item.tipo == "1") tab[1][0]++;
                if(celAux->item.tipo == "2") tab[1][1]++;
                if(celAux->item.tipo == "3") tab[1][2]++;
                if(celAux->item.tipo == "4") tab[1][3]++;
            }else if(celAux->item.nomeO=="3"){
                if(celAux->item.tipo == "1") tab[2][0]++;
                if(celAux->item.tipo == "2") tab[2][1]++;
                if(celAux->item.tipo == "3") tab[2][2]++;
                if(celAux->item.tipo == "4") tab[2][3]++;
            }
            else if(celAux->item.nomeO=="4"){
                if(celAux->item.tipo == "1") tab[3][0]++;
                if(celAux->item.tipo == "2") tab[3][1]++;
                if(celAux->item.tipo == "3") tab[3][2]++;
                if(celAux->item.tipo == "4") tab[3][3]++;
            }
            else if(celAux->item.nomeO=="5"){
                if(celAux->item.tipo == "1") tab[4][0]++;
                if(celAux->item.tipo == "2") tab[4][1]++;
                if(celAux->item.tipo == "3") tab[4][2]++;
                if(celAux->item.tipo == "4") tab[4][3]++;
            }
            celAux = celAux->proximo;
    }

    //mostra a tabela de dados.
    cout<<"================================ TABELA DE ORGÃOS ==================================="<<endl;
    cout<<" "<<endl;
    cout<<"         |        A         |        B         |        O         |        AB        |"<<endl;
    cout <<"--------------------------------------------------------------------------------------"<<endl;
        cout <<"Coração  |        "<< tab[0][0] <<"         |        "<<tab[0][1]<<"         |        "<<tab[0][2]<<"         |        "<<tab[0][3]<<"         |"<<endl;
        cout <<"         |                  |                  |                  |                  | "<<endl;
        cout << "Rim      |        "<< tab[1][0] <<"         |        "<<tab[1][1]<<"         |        "<<tab[1][2]<<"         |        "<<tab[1][3]<<"         |"<<endl;
        cout <<"         |                  |                  |                  |                  |"<<endl;
        cout << "Figado   |        "<< tab[2][0] <<"         |        "<<tab[2][1]<<"         |        "<<tab[2][2]<<"         |        "<<tab[2][3]<<"         |"<<endl;
        cout <<"         |                  |                  |                  |                  | "<<endl;
        cout << "Pângreas |        "<< tab[3][0] <<"         |        "<<tab[3][1]<<"         |        "<<tab[3][2]<<"         |        "<<tab[3][3]<<"         |"<<endl;
        cout <<"         |                  |                  |                  |                  |"<<endl;
        cout << "Córnea   |        "<< tab[4][0] <<"         |        "<<tab[4][1]<<"         |        "<<tab[4][2]<<"         |        "<<tab[4][3]<<"         |"<<endl;
        cout <<"--------------------------------------------------------------------------------------"<<endl;
}

void visualizar(){//chama o procedimento tabela, este então realiza comparações e mostra a tabela de órgãos
    bool resp;
    system("cls");

    do{
      tabela(lendoArqO("orgaos.txt",3));//recebe uma lista de órgãos.

      cout<<"Digite (0) para voltar ao menu principal: ";
      cin>>resp;

    }while(resp != 0);
}

void buscarPaciente(TArvoreBin &arvore){//mostra os dados de um paciente específico através de seu nome.
    bool resp;
    system("cls");
    string resp1;
    cout<<"================================= BUSCA DE PACIENTES ================================"<<endl;
    do{

        cout<<""<<endl;
        cout<<"    Digite o nome do paciente para saber os seus dados: ";
        cin>>resp1;
        lendoArqPA("pacientes.txt",9,arvore);//lê o arquivo de texto.
        cout<<""<<endl;
        pesquisar(arvore,resp1,arvore.raiz);//envia para arvore de pesquisa o nome coletado.
        cout<<""<<endl;

        cout<<"    Dejesa fazer uma nova busca?(1-Nova busca/0-Menu de busca): ";
        cin>>resp;
        system("cls");
        cout<<"================================= BUSCA DE PACIENTES ================================"<<endl;
    }while(resp!=0);
}

void mostrarPacientes(TArvoreBin &arvore){//mostra todos os pacientes cadastrados
    lendoArqPA("pacientes.txt",9,arvore);
    percorrerINOrdem(arvore.raiz);
}

void transplante(){//responsável por realizar a opção de transplante, retirando da lista o paciente operado e o órgão transplantado.
    bool resp,resp1;
    system("cls");

    //instanciação de uma fila, e duas listas.
    TFilaP fp;
    TListaP lp;
    TListaPO lpo;
    criarListaPVazia(lp);
    criarListaPOVazia(lpo);
    TCelulaO pega;

    cout<<"              ========================= FILA PARA O TRANSPLANTE ========================"<<endl;

    TCelulaO *celAux1;
    celAux1 = lendoArqO("orgaos.txt",3).primeiro->proximo;//pegando o primeiro item do ponteiro.

    while (celAux1 != NULL){//preenche a lista de órgãos
        inserirO(lpo, celAux1->item);
        celAux1 = celAux1->proximo;
    }

    TCelula *celAux;
    celAux = lendoArqPF("pacientes.txt",9,fp).primeiro->proximo;

    while (celAux != NULL){//preenche a lista de pacientes.
        inserir(lp, celAux->item);
        celAux = celAux->proximo;
    }

    do{
        if(estaVaziaFP(fp)){//verifica se a fila está vazia
        cout<<"Fila vazia!"<<endl;
        }
        else{
        mostrarFP(fp);

        celAux=lp.primeiro->proximo;
        celAux1=lpo.primeiro->proximo;

        cout<<""<<endl;

        cout<<"Dejesa realizar o transplante no paciente "<<fp.frente->proximo->item.nomeP<<"?(1- Realizar transplante/0- Voltar): ";
        cin>>resp1;
        if (resp1==1){
           desenfileirar(fp);//retira da fila.
           pega.item.nomeO = fp.frente->item.situacao.receber;//pega o tipo sanguíneo e o órgão.
           pega.item.tipo = fp.frente->item.situacao.tipoSang;
           if (estaVaziaFP(fp)){//Verifica se a fila está vazia.
                ofstream outfile;
                outfile.open("pacientes.txt");
            }
            else{
                while (celAux !=NULL){//percorre a lista
                    if (celAux->item.situacao.prioridade==fp.frente->item.situacao.prioridade){//acha o paciente procurado
                        retirarPorChave(lp,celAux->item);//retira da lista.
                    }
                    celAux = celAux->proximo;
                }
                while (celAux1 !=NULL){
                    if (celAux1->item.nomeO==pega.item.nomeO){//acha o órgão
                       if ((celAux1->item.tipo==pega.item.tipo)||(celAux1->item.tipo=="3")){//acha o tipo sanguíneo;3 corresponde ao tipo sanguíneo "O" doador universal.
                            retirarPorChaveO(lpo,celAux1->item);//retira da lista.
                            break;//pega somente um órgão.
                        }
                    }
                    celAux1=celAux1->proximo;
                }
                escrevendoArqPC(lp);//reescreve a lista de pacientes com as alterações feitas.
                escrevendoArqOR(lpo);//reescreve a lista de órgãos com as alterações realizadas.
            }
        }
        system("cls");
        cout<<""<<endl;
        }
        cout<<"Dejesa realizar um novo transplante?(1- Novo transplante/0- Menu Principal): ";
        cin>>resp;
    }while(resp != 0);
}

void consultar(){//consulta os dados dos pacientes
    bool resp;
    int resp1;
    system("cls");
    TArvoreBin arvore;
    do{
        cout<<"================================= BUSCA DE PACIENTES ================================"<<endl;
        cout<<"1 - Buscar os dados de um paciente através de seu nome."<<endl;
        cout<<"2 - Mostrar todos os pacientes cadastrados."<<endl;
        cout<<"3 - Voltar ao menu principal."<<endl;
        cout<<""<<endl;
        cout<<"Digite a opção escolhida: ";
        cin>>resp1;

        switch (resp1){
            case 1:
                buscarPaciente(arvore);
            break;
            case 2:
                mostrarPacientes(arvore);
            break;
            case 3:
                system("cls");
                menu();
            break;
            default:
            cout << "Que tal digitar um número entre 1 a 3 da próxima vez?"<<endl;
            cout<<""<<endl;
        }
        cout<<"    Dejesa fazer uma nova busca?(1-Nova busca/0-Menu principal): ";
        cin>>resp;
        system("cls");
    }while(resp != 0);
}

void cadastrarO(){//cadastra um novo órgão
    bool resp;
    system("cls");
    string vetOrgao[3];
    TOrgao o;

    cout<<"======================== CADASTRO DE ÓRGÃOS E TECIDOS ========================="<<endl;
    do{//COLETA DE DADOS.
        cout<<"Digite o nome do doador: ";
        cin>>o.nomeD;
        cout<<""<<endl;
        do{
            cout<<"Informe qual o órgão ou tecido doado"<<endl;
            cout<<"1- Coração"<<endl;
            cout<<"2- Rim"<<endl;
            cout<<"3- Fígado"<<endl;
            cout<<"4- Pâncreas"<<endl;
            cout<<"5-  Córnea"<<endl;
            cout<<"Digite a opção escolhida: ";
            cin>>o.nomeO;

            if ((o.nomeO != "1")&&(o.nomeO != "2")&&(o.nomeO != "3")&&(o.nomeO != "4")&&(o.nomeO != "5")){
               cout<<"Dados incorretos. Tente novamete!"<<endl;
            }

        }while((o.nomeO != "1")&&(o.nomeO != "2")&&(o.nomeO != "3")&&(o.nomeO != "4")&&(o.nomeO != "5"));

        cout<<""<<endl;
        do{
            cout<<"Informe o tipo sanguíneo"<<endl;
            cout<<"1 - A"<<endl;
            cout<<"2 - B"<<endl;
            cout<<"3 - O"<<endl;
            cout<<"4 - AB"<<endl;
            cout<<"Digite a opção escolhida: ";
            cin>>o.tipo;

            if ((o.tipo != "1")&&(o.tipo!= "2")&&(o.tipo != "3")&&(o.tipo != "4")){
               cout<<"Dados incorretos. Tente novamete!"<<endl;
            }

        }while((o.tipo != "1")&&(o.tipo!= "2")&&(o.tipo != "3")&&(o.tipo != "4"));

        //PREENCHE O VETOR COM OS DADOS COLETADOS
        vetOrgao[2]=o.nomeD;
        vetOrgao[0]=o.nomeO;
        vetOrgao[1]=o.tipo;

        escrevendoArqO("orgaos.txt",vetOrgao,3);//ARMAZENA OS DADOS COLETADOS NO ARQUIVO.

        cout<<""<<endl;
        cout<<"Dejesa cadastrar novamente?(1- Novo cadastro/0- Menu Principal): ";
        cin>>resp;
        system("cls");
        if (resp !=0 ){
           cout<<"======================== CADASTRO DE ÓRGÃOS E TECIDOS ========================="<<endl;
        }
    }while(resp != 0);
}

void cadastrarP(){//cadastra um novo paciente

    bool resp;
    system("cls");
    string vetPacientes[9];
    TPaciente p;
    int converter,gravidade,total;

    cout<<"======================== CADASTRO DE PACIENTES ========================="<<endl;
    do{//COLETA DE DADOS.
        cout<<"Digite o nome: ";
        cin>>p.nomeP;
        cout<<"Digite a idade: ";
        cin>>p.idade;
        cout<<"Digite o cpf: ";
        cin>>p.cpf;
        cout<<"N° do cartão do SUS: ";
        cin>>p.numero;

        cout<<""<<endl;
        do{
            cout<<"Informe qual o órgão ou tecido a ser transplantado"<<endl;
            cout<<"1- Coração"<<endl;
            cout<<"2- Rim"<<endl;
            cout<<"3- Fígado"<<endl;
            cout<<"4- Pâncreas"<<endl;
            cout<<"5- Córnea"<<endl;
            cout<<"Digite a opção escolhida: ";
            cin>>p.situacao.receber;

            if ((p.situacao.receber != "1")&&(p.situacao.receber != "2")&&(p.situacao.receber != "3")&&(p.situacao.receber != "4")&&(p.situacao.receber != "5")){
               cout<<"Dados incorretos. Tente novamete!"<<endl;
            }

        }while((p.situacao.receber != "1")&&(p.situacao.receber != "2")&&(p.situacao.receber != "3")&&(p.situacao.receber != "4")&&(p.situacao.receber != "5"));
        do{
            cout<<"Informe o tipo sanguíneo"<<endl;
            cout<<"1 - A"<<endl;
            cout<<"2 - B"<<endl;
            cout<<"3 - O"<<endl;
            cout<<"4 - AB"<<endl;
            cout<<"Digite a opção escolhida: ";
            cin>>p.situacao.tipoSang;

            if ((p.situacao.tipoSang != "1")&&(p.situacao.tipoSang!= "2")&&(p.situacao.tipoSang != "3")&&(p.situacao.tipoSang != "4")){
               cout<<"Dados incorretos. Tente novamete!"<<endl;
            }

        }while((p.situacao.tipoSang != "1")&&(p.situacao.tipoSang!= "2")&&(p.situacao.tipoSang != "3")&&(p.situacao.tipoSang != "4"));

        cout<<""<<endl;
        cout<<"Digite o tempo de espera(em Meses): ";
        cin>>p.situacao.tempo;

        cout<<""<<endl;
        do{
            cout<<"Informe o estado de saúde do paciente"<<endl;
            cout<<"1 - Grave"<<endl;
            cout<<"2 - Muito grave"<<endl;
            cout<<"3 - Gravíssimo"<<endl;;
            cout<<"Digite a opção escolhida: ";
            cin>>p.situacao.gravidade;

            if ((p.situacao.gravidade != "1")&&(p.situacao.gravidade != "2")&&(p.situacao.gravidade != "3")){
               cout<<"Dados incorretos. Tente novamete!"<<endl;
            }

        }while((p.situacao.gravidade != "1")&&(p.situacao.gravidade != "2")&&(p.situacao.gravidade != "3"));

        //convertendo o número de meses de string para inteiro.
        stringstream ss(p.situacao.tempo);
        ss >> converter;

        //comparando a resposta e atribuindo valores de acordo com uma determinada situação.
        if (p.situacao.gravidade=="1"){
            gravidade=5;
        }
        if (p.situacao.gravidade=="2"){
            gravidade=10;
        }
        if (p.situacao.gravidade=="3"){
            gravidade=20;
        }

        total = converter + gravidade;

        //convertendo de inteiro para string.
        std::stringstream resultado;
        resultado<<total;

        p.situacao.prioridade=resultado.str();

        //PREENCHE O VETOR COM OS DADOS COLETADOS
        vetPacientes[1]=p.nomeP;
        vetPacientes[8]=p.idade;
        vetPacientes[2]=p.cpf;
        vetPacientes[3]=p.numero;
        vetPacientes[4]=p.situacao.tipoSang;
        vetPacientes[5]=p.situacao.tempo;
        vetPacientes[6]=p.situacao.gravidade;
        vetPacientes[7]=p.situacao.prioridade;
        vetPacientes[0]=p.situacao.receber;

        escrevendoArqP("pacientes.txt",vetPacientes,9);//INSERE OS DADOS COLETADOS NO ARQUIVO.

        cout<<""<<endl;
        cout<<"Dejesa cadastrar novamente?(1- Novo cadastro/0- Menu Principal): ";
        cin>>resp;
        system("cls");
        if (resp !=0 ){
           cout<<"======================== CADASTRO DE PACIENTES ========================="<<endl;
        }
    }while(resp != 0);
}

void menu(){//procedimento para mostrar os códigos de operações e receber o código.

    int i;

    do{

    cout<<"   ================================================================================================================== "<<endl;
    cout<<"  |             s$$$$       .s$                                                                                      |"<<endl;
    cout<<"  |        ,    $$$$$.      s$                                                                                       |"<<endl;
    cout<<"  |        $   $$$$$$s     s$                                                                                        |"<<endl;
    cout<<"  |       s$    $$$$$$$s   $$$                                                                                       |"<<endl;
    cout<<"  |       $$     $$$$$$s.   $$s                                                                                      |"<<endl;
    cout<<"  |        $.     $$$$$$$s .s$$$                                                                                     |"<<endl;
    cout<<"  |       `$$.     $$$$$$$ $$$$    s       =======- Seja bem-vindo! Qual operação você deseja realizar? -=======     |"<<endl;
    cout<<"  |         $$s     $$$$$$s$$$    s$      |         ____________________________________________________        |    |"<<endl;
    cout<<"  |          $$s    $$$$$s$$$$`   s$$     |        |Digite 1: Para cadastrar um novo paciente;          |       |    |"<<endl;
    cout<<"  |      s.  $$$$   s$$$$$$$$  .s $$      |        |                                                    |       |    |"<<endl;
    cout<<"  |      $$ s$$$$..s$$$$$$$$$$$$$ $       |        |Digite 2: Para cadastrar um novo orgão;             |       |    |"<<endl;
    cout<<"  |      s$.s$$$$s$$$$$$$$$$$$$$$ $       |        |                                                    |       |    |"<<endl;
    cout<<"  |     s$$$$$$$$$$$$$$$$$$$$$$$          |        |Digite 3: Para realizar um transplante;             |       |    |"<<endl;
    cout<<"  |    s$$$ssss$$$$$$$$$$ssss$$$s         |        |                                                    |       |    |"<<endl;
    cout<<"  |   $$s§§§§§§§§§s$$$$s§§§§§§§§§$$       |        |Digite 4: Para consultar os dados dos pacientes;    |       |    |"<<endl;
    cout<<"  |    §§§§§§§§§§§§§s$s§§§§§§§§§§§§§      |        |                                                    |       |    |"<<endl;
    cout<<"  |   §§§§§§§§§§§§§§§s§§§§§§§§§§§§§§      |        |Digite 5: Para visualizar o estoque de órgãos;      |       |    |"<<endl;
    cout<<"  |    §§§§§§§§§§§§§§§§§§§§§§§§§§§§§      |        |                                                    |       |    |"<<endl;
    cout<<"  |     §§§§§§§§§§§§§§§§§§§§§§§§§§§       |        |Digite 6: Para finalizar o programa.                |       |    |"<<endl;
    cout<<"  |      §§§§§§§§§§§§§§§§§§§§§§§§§        |         ----------------------------------------------------        |    |"<<endl;
    cout<<"  |       §§§§§§§§§§§§§§§§§§§§§§§         |                                                                     |    |"<<endl;
    cout<<"  |         §§§§§§§§§§§§§§§§§§§            =====================================================================     |"<<endl;
    cout<<"  |           §§§§§§§§§§§§§§§                                                                                        |"<<endl;
    cout<<"  |             §§§§§§§§§§§                                                                                          |"<<endl;
    cout<<"  |                §§§§§                                                                                             |"<<endl;
    cout<<"  |                  §                                                                                               |"<<endl;
    cout<<"   ================================================================================================================== "<<endl;
    cout<<"   Código de operação: ";
    cin>>i;

    switch(i){
            case 1:
                cadastrarP();//caso 1, cadastro de pacientes.
            break;
            case 2:
                cadastrarO();//caso 2, cadastro de órgãos.
            break;
            case 3:
                transplante();//caso 3, realiza a operação de transplante.
            break;
            case 4:
                consultar();//caso 4, consulta os dados dos paciente.
            break;
            case 5:
                visualizar();//caso 5, vizualiza o banco de órgãos.
            break;
            case 6:
                break;//caso 6, finaliza o programa.
            default:
            cout << "Que tal digitar um número entre 1 a 6 da próxima vez?";
        }
        system("cls");//limpa a tela para chamada do novo menu.
    }while(i!=6);
}
