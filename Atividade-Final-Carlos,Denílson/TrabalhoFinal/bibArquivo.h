#ifndef BIBLENDOARQP_H_INCLUDED
#define BIBLENDOARQP_H_INCLUDED
#include "bibArvoreP.h"
#include "bibTADListaP.h"

using namespace std;

//Biblioteca responsável por realizar a leitura e preenchimento de dados em arquivo.

TListaP lendoArqPA(string nomeArq, int quantTokens, TArvoreBin &a);
TListaP lendoArqPF(string nomeArq, int quantTokens,TFilaP &fp);
TListaPO lendoArqO(string nomeArq, int quantTokens);
int escrevendoArqP(string nomeArq, string vetDados[], int quantTokens);
int escrevendoArqO(string nomeArq, string vetDados[], int quantTokens);
int escrevendoArqOR(TListaPO lpo);
int escrevendoArqPC(TListaP lp);

#endif // BIBLENDOARQP_H_INCLUDED
