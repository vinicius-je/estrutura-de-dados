/*********************************
#
# ESTRUTURA DE DADOS
#
# tadpilha.c
#
*********************************/
#include "tadpilha.h"

Pilha criaPilha(){
    return criaLista();
}

tdado empilha(Pilha pilha, tdado dado){
    appendLista(pilha, dado);
    return dado;
}

tdado desempilha(Pilha pilha){
    tdado dadoExcluido = dadoLista(pilha, 0);
    removeLista(pilha, 0);
    return dadoExcluido;
}

tdado topoPilha(Pilha pilha){
    return primLista(pilha);
}

int tamPilha(Pilha pilha){
    return lenLista(pilha);
}

int vaziaPilha(Pilha pilha){
    return lenLista(pilha) == 0;
}

Lista pilha2lista(Pilha pilha){
    Lista lst = criaLista();

    for(int i = 0; i < lenLista(pilha); i++)
        appendLista(lst, dadoLista(pilha, i));

    return lst;
}