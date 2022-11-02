#ifndef BIBTADLISTAP_H_INCLUDED
#define BIBTADLISTAP_H_INCLUDED

using namespace std;

//Lista que armazenará os dados do paciente

struct TSituacao{
    string receber;
    string tipoSang;
    string tempo;
    string gravidade;
    string prioridade;
};

struct TPaciente{
    string nomeP;
    string idade;
    string cpf;
    string numero;
    TSituacao situacao;
};

struct TCelula{
    TPaciente item;
    TCelula *proximo;
};

struct TListaP{
    TCelula *primeiro;
    TCelula *ultimo;
    int contItens;
};

void criarListaPVazia(TListaP &lp);
void inserir(TListaP &lp, TPaciente x);
void mostrarLP(TListaP lp);
void retirarPorChave(TListaP &lp, TPaciente c);
bool estaVazia(TListaP lp);

//Lista que Armazenará os dados do órgão

struct TOrgao{
    string nomeD;
    string nomeO;
    string tipo;
};

struct TCelulaO{
    TOrgao item;
    TCelulaO *proximo;
};

struct TListaPO{
    TCelulaO *primeiro;
    TCelulaO *ultimo;
    int contItens;
};

void criarListaPOVazia(TListaPO &lpo);
void inserirO(TListaPO &lpo, TOrgao x);
void mostrarLPO(TListaPO lpo);
void retirarPorChaveO(TListaPO &lpo, TOrgao n);

//FILA DE PRIORIDADE

struct TCelulaFP{
    TPaciente item;
    TCelulaFP *proximo;
};

struct TFilaP{
    TCelulaFP *frente;
    TCelulaFP *tras;
    int contItens;
};

void criarFilaPVazia(TFilaP &fp);
void enfileirar(TFilaP &fp,TPaciente x);
void mostrarFP(TFilaP fp);
void desenfileirar(TFilaP &fp);
bool estaVaziaFP(TFilaP fp);

#endif // BIBTADLISTAP_H_INCLUDED
