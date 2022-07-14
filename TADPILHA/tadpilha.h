/*********************************
#
# ESTRUTURA DE DADOS
#
# tadpilha.h
#
*********************************/
#ifndef TADFILA_H
#define TADFILA_H
#endif
#include "tadlista.h"

typedef Lista Pilha;
/*********************************
#
# INTERFACE DA TADPILA
#
**********************************/
Pilha criaPilha();
tdado empilha(Pilha pilha, tdado dado);
tdado desempilha(Pilha pilha);
tdado topoPilha(Pilha pilha);
int tamPilha(Pilha pilha);
int vaziaPilha(Pilha pilha);
Lista pilha2lista(Pilha pilha);