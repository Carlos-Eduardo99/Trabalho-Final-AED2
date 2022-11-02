#include <iostream>
#include "bibArvoreP.h"

using namespace std;

//IMPLEMENTAÇÃO DA ÁRVORE DE BUSCA.

void criarArvoreBinVazia(TArvoreBin &a, string n){//CRIA UMA ÁRVORE VAZIA.
    a.nomeArvore = n;
    a.contItens = 0;
    a.raiz = NULL;
}

void inserirA(TArvoreBin &a, TNo *&no, TPaciente i){//INSERIR NA ÁRVORE.
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
                    cout << "Não posso inserir. Item já existe!" << endl;
                 }
            }
        }

    }
}

void pesquisar(TArvoreBin a, string c, TNo *&n){//MOSTRA OS DADOS DE UM PACIENTE ATRAVÉS DE SEU NOME.
    if (n == NULL){
        cout <<"O Paciente "<<c<<" não foi encontrado em nossos registros!" << endl;
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
                cout<<"                  |     N° do cartão do SUS: "<<n->item.numero<<endl;
                if (n->item.situacao.receber=="1"){
                   cout<<"                  |     Órgão ou tecido a ser transpantado: Coração"<<endl;
                }
                else{
                    if (n->item.situacao.receber=="2"){
                       cout<<"                  |     Órgão ou tecido a ser transpantado: Rim"<<endl;
                    }
                    else{
                        if (n->item.situacao.receber=="3"){
                           cout<<"                  |     Órgão ou tecido a ser transpantado: Fígado"<<endl;
                        }
                        else{
                            if (n->item.situacao.receber=="4"){
                               cout<<"                  |     Órgão ou tecido a ser transpantado: Pâncreas"<<endl;
                            }
                            else{
                                if (n->item.situacao.receber=="5"){
                                   cout<<"                  |     Órgão ou tecido a ser transpantado: Córnea"<<endl;
                                }
                            }
                        }
                    }
                }
                if (n->item.situacao.tipoSang=="1"){
                   cout<<"                  |     Tipo sanguíneo: A"<<endl;
                }
                else{
                    if (n->item.situacao.tipoSang=="2"){
                       cout<<"                  |     Tipo sanguíneo: B"<<endl;
                    }
                    else{
                        if (n->item.situacao.tipoSang=="3"){
                           cout<<"                  |     Tipo sanguíneo: O"<<endl;
                        }
                        else{
                            if (n->item.situacao.tipoSang=="4"){
                               cout<<"                  |     Tipo sanguíneo: AB"<<endl;
                            }
                        }
                    }
                }
                cout<<"                  |     Tempo de espera: "<<n->item.situacao.tempo<<" meses"<<endl;
                if (n->item.situacao.gravidade=="1"){
                   cout<<"                  |     Estado de Saúde: Grave"<<endl;
                }
                else{
                    if (n->item.situacao.gravidade=="2"){
                       cout<<"                  |     Estado de Saúde: Muito Grave"<<endl;
                    }
                    else{
                        if (n->item.situacao.gravidade=="3"){
                           cout<<"                  |     Estado de Saúde: Gravíssimo"<<endl;
                        }
                    }
                }
                cout<<"                  |     Nível de Prioridade: "<<n->item.situacao.prioridade<<endl;
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
                cout<<"                  |     N° do cartão do SUS: "<<n->item.numero<<endl;
                if (n->item.situacao.receber=="1"){
                   cout<<"                  |     Órgão ou tecido a ser transpantado: Coração"<<endl;
                }
                else{
                    if (n->item.situacao.receber=="2"){
                       cout<<"                  |     Órgão ou tecido a ser transpantado: Rim"<<endl;
                    }
                    else{
                        if (n->item.situacao.receber=="3"){
                           cout<<"                  |     Órgão ou tecido a ser transpantado: Fígado"<<endl;
                        }
                        else{
                            if (n->item.situacao.receber=="4"){
                               cout<<"                  |     Órgão ou tecido a ser transpantado: Pâncreas"<<endl;
                            }
                            else{
                                if (n->item.situacao.receber=="5"){
                                   cout<<"                  |     Órgão ou tecido a ser transpantado: Córnea"<<endl;
                                }
                            }
                        }
                    }
                }
                if (n->item.situacao.tipoSang=="1"){
                   cout<<"                  |     Tipo sanguíneo: A"<<endl;
                }
                else{
                    if (n->item.situacao.tipoSang=="2"){
                       cout<<"                  |     Tipo sanguíneo: B"<<endl;
                    }
                    else{
                        if (n->item.situacao.tipoSang=="3"){
                           cout<<"                  |     Tipo sanguíneo: O"<<endl;
                        }
                        else{
                            if (n->item.situacao.tipoSang=="4"){
                               cout<<"                  |     Tipo sanguíneo: AB"<<endl;
                            }
                        }
                    }
                }
                cout<<"                  |     Tempo de espera: "<<n->item.situacao.tempo<<" meses"<<endl;
                if (n->item.situacao.gravidade=="1"){
                   cout<<"                  |     Estado de Saúde: Grave"<<endl;
                }
                else{
                    if (n->item.situacao.gravidade=="2"){
                       cout<<"                  |     Estado de Saúde: Muito Grave"<<endl;
                    }
                    else{
                        if (n->item.situacao.gravidade=="3"){
                           cout<<"                  |     Estado de Saúde: Gravíssimo"<<endl;
                        }
                    }
                }
                cout<<"                  |     Nível de Prioridade: "<<n->item.situacao.prioridade<<endl;
                cout<<"                  ================================================"<<endl;
                cout<<" "<<endl;
        percorrerINOrdem(n->direita);
    }
}
