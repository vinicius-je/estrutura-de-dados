/*********************************
#
# ESTRUTURA DE DADOS
#
# tadfila.h
#
*********************************/
#ifndef TADFILA_H_ 
#define TADFILA_H_
#endif
#include "tadlista.h"

typedef Lista Fila;
/*********************************
#
# INTERFACE DA TADFILA
#
**********************************/
Fila criaFila();
tdado enfileira(Fila fila, tdado dado);
tdado desenfileira(Fila fila);
tdado cabecaFila(Fila fila);
tdado caudaFila(Fila fila);
int tamFila(Fila fila);
int vaziaFila(Fila fila);
Lista fila2lista(Fila fila);