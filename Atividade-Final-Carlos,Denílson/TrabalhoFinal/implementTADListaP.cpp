#include <iostream>
#include "bibTADListaP.h"

using namespace std;

//IMPLEMENTA��O DA LISTA POR PONTEIRO DOS PACIENTES

void criarListaPVazia(TListaP &lp){
    lp.primeiro = new TCelula;
    lp.ultimo = lp.primeiro;
    lp.primeiro->proximo = NULL;
    lp.contItens = 0;
}

bool estaVazia(TListaP lp){
    return lp.primeiro == lp.ultimo;
}

void inserir(TListaP &lp, TPaciente x){
    lp.ultimo ->proximo = new TCelula;
    lp.ultimo = lp.ultimo->proximo;
    lp.ultimo->item = x;
    lp.ultimo->proximo = NULL;
    lp.contItens++;
}

void mostrarLP(TListaP lp){
    TCelula *celAux;
    celAux = lp.primeiro->proximo;

    if (estaVazia(lp)){
       cout<<"Nada para mostrar. Lista vazia!!"<<endl;
    }
    else{
        cout<<"===== MOSTRANDO LISTA ======"<<endl;
        while (celAux != NULL){
            cout<<"Nome: "<<celAux->item.nomeP<<endl;
            cout<<"Idade: "<<celAux->item.idade<<endl;
            cout<<"CPF: "<<celAux->item.cpf<<endl;
            cout<<"N� do cart�o do SUS: "<<celAux->item.numero<<endl;
            cout<<"Tipo sangu�neo: "<<celAux->item.situacao.tipoSang<<endl;
            cout<<"Tempo de espera: "<<celAux->item.situacao.tempo<<endl;
            cout<<"Estado de Sa�de: "<<celAux->item.situacao.gravidade<<endl;
            cout<<"N�vel de Prioridade: "<<celAux->item.situacao.prioridade<<endl;
            cout<<"�rg�o ou tecido a ser transplantado: "<<celAux->item.situacao.receber<<endl;
            celAux = celAux->proximo;
        }
    }
}

TCelula *pegaAnterior(TListaP lp, TPaciente c){
    TCelula *celAux;
    bool achou = false;

    celAux = lp.primeiro;

    while (celAux->proximo != NULL){
        if (celAux->proximo->item.situacao.prioridade == c.situacao.prioridade){
           achou = true;
           return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
       return NULL;
    }
}

void retirarPorChave(TListaP &lp, TPaciente c){
    TCelula *p = pegaAnterior(lp,c);
    TCelula *q;

    if (p == NULL){
       cout<<"Chave n�o encontrada"<<endl;
    }
    else{
        q = p->proximo;
        p->proximo = q->proximo;
        delete(q);
        lp.contItens--;
    }
}

//IMPLEMENTA��O DA LISTA POR PONTEIRO DOS �RG�OS

TCelulaO *pegaAnteriorO(TListaPO lpo, TOrgao n){
    TCelulaO *celAux;
    bool achou = false;

    celAux = lpo.primeiro;

    while (celAux->proximo != NULL){
        if ((celAux->proximo->item.nomeO == n.nomeO)&&(celAux->proximo->item.tipo == n.tipo)){
           achou = true;
           return celAux;
        }
        celAux = celAux->proximo;
    }
    if (achou == false){
       return NULL;
    }
}

void retirarPorChaveO(TListaPO &lpo, TOrgao n){
    TCelulaO *p = pegaAnteriorO(lpo,n);
    TCelulaO *q;

    if (p == NULL){
       cout<<"Chave n�o encontrada"<<endl;
    }
    else{
        q = p->proximo;
        p->proximo = q->proximo;
        delete(q);
        lpo.contItens--;
    }
}

void criarListaPOVazia(TListaPO &lpo){
    lpo.primeiro = new TCelulaO;
    lpo.ultimo = lpo.primeiro;
    lpo.primeiro->proximo = NULL;
    lpo.contItens = 0;
}

bool estaVaziaO(TListaPO lpo){
    return lpo.primeiro == lpo.ultimo;
}

void inserirO(TListaPO &lpo, TOrgao x){
    lpo.ultimo ->proximo = new TCelulaO;
    lpo.ultimo = lpo.ultimo->proximo;
    lpo.ultimo->item = x;
    lpo.ultimo->proximo = NULL;
    lpo.contItens++;
}

void mostrarLPO(TListaPO lpo){
    TCelulaO *celAux;
    celAux = lpo.primeiro->proximo;

    if (estaVaziaO(lpo)){
       cout<<"Nada para mostrar. Lista vazia!!"<<endl;
    }
    else{
        cout<<"===== MOSTRANDO FILA ======"<<endl;
        while (celAux != NULL){
            cout<<"Nome do doador: "<<celAux->item.nomeD<<endl;
            cout<<"�rg�o doado: "<<celAux->item.nomeO<<endl;
            cout<<"Tipo sangu�neo: "<<celAux->item.tipo<<endl;
            celAux = celAux->proximo;
        }
    }
}

//IMPLEMENTA��O DA FILA POR PONTEIRO

void criarFilaPVazia(TFilaP &fp){
    fp.frente = new TCelulaFP;
    fp.tras = fp.frente;
    fp.frente->proximo = NULL;
    fp.contItens = 0;
}

bool estaVaziaFP(TFilaP fp){
    return fp.contItens == 0;
}

void enfileirar(TFilaP &fp,TPaciente x){
    fp.tras->proximo = new TCelulaFP;
    fp.tras = fp.tras -> proximo;
    fp.tras->item = x;
    fp.tras ->proximo = NULL;
    fp.contItens ++;
}

void mostrarFP(TFilaP fp){
    TCelulaFP *n;
    n = fp.frente ->proximo;
    int posicao=1;

    if (estaVaziaFP(fp)){
       cout<<"Nada para mostrar. Fila vazia!!"<<endl;
    }
    else{
        //cout<<"                  ================ MOSTRANDO FILA ====================="<<endl;
        while (n != NULL){
            cout<<""<<endl;
            cout<<"                  ==============================================="<<endl;
                cout<<"                  |     Posi��o na Fila: "<<posicao<<"�"<<endl;
                cout<<"                  |     Nome: "<<n->item.nomeP<<endl;
                cout<<"                  |     Idade: "<<n->item.idade<<endl;
                cout<<"                  |     CPF: "<<n->item.cpf<<endl;
                cout<<"                  |     N� do cart�o do SUS: "<<n->item.numero<<endl;
                if (n->item.situacao.receber=="1"){
                   cout<<"                  |     �rg�o ou tecido a ser transpantado: Cora��o"<<endl;
                }
                else{
                    if (n->item.situacao.receber=="2"){
                       cout<<"                  |     �rg�o ou tecido a ser transpantado: Rim"<<endl;
                    }
                    else{
                        if (n->item.situacao.receber=="3"){
                           cout<<"                  |     �rg�o ou tecido a ser transpantado: F�gado"<<endl;
                        }
                        else{
                            if (n->item.situacao.receber=="4"){
                               cout<<"                  |     �rg�o ou tecido a ser transpantado: P�ncreas"<<endl;
                            }
                            else{
                                if (n->item.situacao.receber=="5"){
                                   cout<<"                  |     �rg�o ou tecido a ser transpantado: C�rnea"<<endl;
                                }
                            }
                        }
                    }
                }
                if (n->item.situacao.tipoSang=="1"){
                   cout<<"                  |     Tipo sangu�neo: A"<<endl;
                }
                else{
                    if (n->item.situacao.tipoSang=="2"){
                       cout<<"                  |     Tipo sangu�neo: B"<<endl;
                    }
                    else{
                        if (n->item.situacao.tipoSang=="3"){
                           cout<<"                  |     Tipo sangu�neo: O"<<endl;
                        }
                        else{
                            if (n->item.situacao.tipoSang=="4"){
                               cout<<"                  |     Tipo sangu�neo: AB"<<endl;
                            }
                        }
                    }
                }
                cout<<"                  |     Tempo de espera: "<<n->item.situacao.tempo<<" meses"<<endl;
                if (n->item.situacao.gravidade=="1"){
                   cout<<"                  |     Estado de Sa�de: Grave"<<endl;
                }
                else{
                    if (n->item.situacao.gravidade=="2"){
                       cout<<"                  |     Estado de Sa�de: Muito Grave"<<endl;
                    }
                    else{
                        if (n->item.situacao.gravidade=="3"){
                           cout<<"                  |     Estado de Sa�de: Grav�ssimo"<<endl;
                        }
                    }
                }
                cout<<"                  |     N�vel de Prioridade: "<<n->item.situacao.prioridade<<endl;
                cout<<"                  ================================================"<<endl;
            n = n->proximo;
            posicao++;
        }
    }
}

void desenfileirar(TFilaP &fp){
    if (estaVaziaFP(fp)){
       cout<<"N�o � poss�vel desenfileirar. Lista Vazia!"<<endl;
    }
    else{
        TCelulaFP *aux = fp.frente;
        fp.frente = fp.frente ->proximo;
        delete(aux);
        fp.contItens --;
    }
}
