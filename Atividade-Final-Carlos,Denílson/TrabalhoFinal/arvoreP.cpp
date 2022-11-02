#include <iostream>
#include "bibArvoreP.h"

using namespace std;

//IMPLEMENTA��O DA �RVORE DE BUSCA.

void criarArvoreBinVazia(TArvoreBin &a, string n){//CRIA UMA �RVORE VAZIA.
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserirA(TArvoreBin &a, TNo *&no, TPaciente i){//INSERIR NA �RVORE.
    if (no == NULL){ // CASO BASE/PARADA
        no = new TNo;
        no->item = i;
        no->esquerda = NULL;
        no->direita = NULL;
        a.contItens++;
        if (a.raiz == NULL){
            a.raiz = no;
        }
    }
    else{
        if (i.nomeP < no->item.nomeP){ // chamada recursiva ESQ
            inserirA(a,no->esquerda,i);
        }
        else{
            if (i.nomeP > no->item.nomeP){ // chamada recursiva DIR
                inserirA(a,no->direita,i);
            }
            else{
                if (i.nomeP == no->item.nomeP){
                    cout << "N�o posso inserir. Item j� existe!" << endl;
                 }
            }
        }

    }
}

void pesquisar(TArvoreBin a, string c, TNo *&n){//MOSTRA OS DADOS DE UM PACIENTE ATRAV�S DE SEU NOME.
    if (n == NULL){
        cout <<"O Paciente "<<c<<" n�o foi encontrado em nossos registros!" << endl;
    }
    else {
        if (c < n->item.nomeP){
            pesquisar(a, c, n->esquerda);
        }
        else {
            if (c > n->item.nomeP){
                pesquisar(a, c, n->direita);
            }
            else{
                cout<<"                  ================ MOSTRANDO DADOS =============="<<endl;
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
            }
        }
    }

}

void percorrerINOrdem(TNo *&n){//MOSTRA TODOS OS DADOS DOS PACIENTES CADASTRADOS.
    if(n!=NULL){
        percorrerINOrdem(n->esquerda);
                cout<<"                  ================ MOSTRANDO DADOS =============="<<endl;
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
                cout<<" "<<endl;
        percorrerINOrdem(n->direita);
    }
}
