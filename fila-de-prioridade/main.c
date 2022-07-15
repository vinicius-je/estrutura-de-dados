#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/************************************
# Fila de Prioridade
# Critério de prioridade: 1, 2 e 3
************************************/
typedef void *tdado;

typedef struct no{
    tdado nome;
    int prioridade;
    struct no *proximo;
} tNo;

typedef tNo *pno;

typedef struct{
    pno primeiro;
    pno ultimo;
    int tamanho;
} tcabec;

typedef tcabec *Fila;

Fila criarFila(){
    Fila fila = (Fila)malloc(sizeof(tcabec));
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
    return fila;
}

void InserirNaFila(Fila fila, tdado nome, int prioridade){
    pno novoNo = (pno)malloc(sizeof(tNo));
    
    if(novoNo){
        novoNo->nome = nome;
        novoNo->prioridade = prioridade;
        novoNo->proximo = NULL;
        if(fila->primeiro == NULL){
            fila->primeiro = novoNo;
            fila->ultimo = novoNo;
        }else{
            pno noAux = (pno)malloc(sizeof(tNo));
            noAux = fila->primeiro;
            // avança o no se existir o próximo nó e se a prioridade é menor
            while(noAux->proximo && noAux->proximo->prioridade <= prioridade){
                noAux = noAux->proximo;
            }
            /* verifica se já existe a prioridade (1) na fila,
            se houver o elemento, será adicionado ao próximo do último
            elemento de prioridade (1), se não será adicionado no meio ou no final
            conforme a prioridade (2 ou 3)*/
            if(!noAux->proximo && novoNo->prioridade == 1){
                novoNo->proximo = fila->primeiro;
                fila->primeiro = novoNo;
            }else{
                novoNo->proximo = noAux->proximo;
                noAux->proximo = novoNo;
            }
        }
        fila->tamanho++;
    }else{
        printf("\n\nErro ao alocar espaço de memoria.\n");
    }
}

pno removerNaFila(Fila fila){
    tNo *noRemover = (pno)malloc(sizeof(tNo));

    if(noRemover){
        noRemover = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
    }else{
        printf("\n\nErro ao alocar memoria.\n");
    }
    fila->tamanho--;
    return noRemover;
}

void imprimir(Fila fila){
    tNo *noAux = (pno)malloc(sizeof(tNo));
    noAux = fila->primeiro;
    printf("Fila: \n");
    while(noAux){
        printf("nome: %s - prioridade: %d\n", noAux->nome, noAux->prioridade);
        noAux = noAux->proximo;
    }
}

int main(){
    Fila fila = criarFila();
    int opcao, prioridade;
    char *stringAux;
    tNo *noRemovido = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao){
            case 1:
                stringAux = (char *)malloc(100 * sizeof(char));
                printf("Nome: ");
                gets(stringAux);
                fflush(stdin);
                printf("Prioridade: ");
                scanf("%d", &prioridade);
                fflush(stdin);
                InserirNaFila(fila, stringAux, prioridade);
                break;
            case 2:
                noRemovido = removerNaFila(fila);
                printf("O %s saiu da fila!", noRemovido->nome);
                break;
            case 3:
                imprimir(fila);
                break;
            default:
                if(opcao != 0){
                    printf("Opcao invalida!");
                }
                break;
            }
    }while(opcao != 0);

    return 0;
}