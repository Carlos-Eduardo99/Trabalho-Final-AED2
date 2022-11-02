#ifndef BIBARVOREP_H_INCLUDED
#define BIBARVOREP_H_INCLUDED
#include "bibTADListaP.h"

using namespace std;

struct TNo{
    TPaciente item;
    TNo *esquerda;
    TNo *direita;
};

struct TArvoreBin{
    string nomeArvore;
    int contItens;
    TNo *raiz;
};

void criarArvoreBinVazia(TArvoreBin &a, string n);
void inserirA(TArvoreBin &a, TNo *&no, TPaciente i);
void pesquisar(TArvoreBin a, string c, TNo *&n);
void percorrerINOrdem(TNo *&no);

#endif // BIBARVOREP_H_INCLUDED
