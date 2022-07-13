/*********************************
#
# ESTRUTURA DE DADOS
#
# tadfila.c
#
*********************************/
#include "tadfila.h"

Fila criaFila(){
	return criaLista();
}

tdado enfileira(Fila fila, tdado dado){
	appendLista(fila, dado);
	return dado;
}

tdado desenfileira(Fila fila){
	tdado dadoExcluido = dadoLista(fila, 0);
	removeLista(fila, 0);
	return dadoExcluido;
}

tdado cabecaFila(Fila fila){
	return primlista(fila);
}

tdado caudaFila(Fila fila){
	return ultLista(fila);
}

int tamFila(Fila fila){
	return lenLista(fila);
}

int vaziaFila(Fila fila){
	return lenLista(fila) == 0;
}

Lista fila2lista(Fila fila){
	Lista lst = criaLista();
	
	for(int i = 0; i < lenLista(fila); i++)
		appendLista(lst, dadoLista(fila, i));

	return lst;
}