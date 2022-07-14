#include <stdio.h>
#include <stdlib.h>

// Operações somente no topo da pilha

typedef struct no{
    int valor;
    struct no *proximo;
} tNo;

typedef tNo *pno;

typedef struct{
    pno primeiro;
    pno ultimo;
    int tamanho;
} tcabec;

typedef tcabec *Pilha;

Pilha criarPilha(){
    Pilha pilha = (Pilha)malloc(sizeof(tcabec));
    pilha->primeiro = NULL;
    pilha->ultimo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void inserirNaPilha(Pilha pilha, int valor){
    tNo *novoNo = (pno)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = valor;
        if(pilha->primeiro == NULL){
            novoNo->proximo = NULL;
            pilha->primeiro = novoNo;
        }else{
            novoNo->proximo = pilha->primeiro;
            pilha->primeiro = novoNo;
        }
    
        pilha->tamanho++;
    }else{
        printf("Error: Nao foi possivel alocar memoria\n");
    }
}

pno removerNaPilha(Pilha pilha){
    tNo *noRemover = (pno)malloc(sizeof(tNo));

    if(noRemover){
        noRemover = pilha->primeiro;
        // A primeira posição recebe o segundo elemento
        pilha->primeiro = noRemover->proximo;
        pilha->tamanho--;
    }else{
        printf("Error: Nao foi possivel alocar memoria\n");
    }
    return noRemover;
}

void imprimirPilha(Pilha pilha){
    tNo *noAux = (pno)malloc(sizeof(tNo));
    noAux = pilha->primeiro;
    printf("Pilha: ");
    while(noAux){
        printf("%d ", noAux->valor);
        noAux = noAux->proximo;
    }
}

int main(){
    Pilha pilha = criarPilha();
    tNo *elementoRemovido = NULL;
    int opcao, valor;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirNaPilha(pilha, valor);
                break;
            case 2:
                elementoRemovido = removerNaPilha(pilha);
                printf("O item %d foi removido da pilha", *elementoRemovido);
                break;
            case 3:
                imprimirPilha(pilha);
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