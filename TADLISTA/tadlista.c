#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"
/*********************************
#
# IMPLEMENTAÇÃO TADLISTA    
#
**********************************/
Lista criaLista(){
    Lista lst = (Lista)malloc(sizeof(tcabec));
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    lst->tamanho = 0;
    return lst;
}

Lista appendLista(Lista lst, tdado dado){
    if(lst == NULL) return NULL;

    pnoh novoNo = (pnoh)malloc(sizeof(tnode));
    novoNo->proximo = NULL;
    novoNo->dado = dado;

    if(lst->tamanho == 0){
        lst->primeiro = novoNo;
        lst->ultimo = novoNo;
    }
    else{
        lst->ultimo->proximo = novoNo;
        lst->ultimo = novoNo;
    }
    lst->tamanho++;
    return lst;
}

int lenLista(Lista lst){
    return lst->tamanho;
}

tdado primlista(Lista lst){
    return lst->primeiro->dado;
}

tdado ultLista(Lista lst){
    return lst->ultimo->dado;
}

tdado dadoLista(Lista lst, int index) {
    int contador = 0;
    pnoh noRemover;

    if((lst == NULL) || (index < 0) || (index >= lst->tamanho)) 
        return NULL;

    noRemover = lst->primeiro;
    while(contador != index){
        contador++;
        noRemover = noRemover->proximo;
    }
    return noRemover->dado;
}

int indexLista(Lista lst, tdado dado) {
    int tamanho = lst->tamanho;

    for(int posicao=0; posicao < tamanho; posicao++){
        if(dadoLista(lst, posicao) == dado)
            return posicao;
    }
    return -1;
}

Lista insertLista(Lista lst, tdado dado, int index){
    int contador = 0;

    if(lenLista(lst) == 0 || lenLista(lst) == index){
        appendLista(lst, dado);
    }else{
        pnoh novoNo = (pnoh)malloc(sizeof(tnode));
        novoNo->dado = dado;

        pnoh anterior = lst->primeiro;
        while(contador != index - 1){
            anterior = anterior->proximo;
        }
        novoNo->proximo = anterior->proximo;
        anterior->proximo = novoNo;
    }
    return lst;
}

Lista removeLista(Lista lst, int index){
    pnoh noRemover, noAnterior;
    int tamanho = lenLista(lst);

    noAnterior = lst->primeiro;

    if((lst == NULL || index < 0 || index > tamanho))
        return NULL;
    
    if (index == 0){
        noRemover = lst->primeiro;
        lst->primeiro = noRemover->proximo;
    }else{
        // acessar o elemento anterior (index - 1) ao no que será removido
        while (--index){
            noAnterior = noAnterior->proximo;
        }
        noRemover = noAnterior->proximo;
        noAnterior->proximo = noRemover->proximo;
    }
    
    lst->tamanho--;
    free(noRemover);
}