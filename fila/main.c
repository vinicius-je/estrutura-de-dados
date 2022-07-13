#include <stdio.h>
#include <stdlib.h>

// FIFO - First In, First Out

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

typedef tcabec *Fila;

Fila criarFila(){
    Fila fila = (Fila)malloc(sizeof(tcabec));
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
    return fila;
}

// Inserção de elementos apenas no final da fila
void inserirNaFila(Fila fila, int num){
    tNo *novoNo = (pno)malloc(sizeof(tNo));
    
    if(novoNo){
        novoNo->valor = num;
        novoNo->proximo = NULL;
        if(fila->primeiro == NULL){
            fila->primeiro = novoNo;
            fila->ultimo = novoNo;
        }else{
            fila->ultimo->proximo = novoNo;
            fila->ultimo = novoNo;
        }
    }else{
        printf("\n\nErro ao alocar memoria.\n");
    }
    fila->tamanho++;
}
// Remover elemento, sempre será o primeiro elemento
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

void imprimirFila(Fila fila){
    tNo *noAux = (pno)malloc(sizeof(tNo));
    noAux = fila->primeiro;
    printf("Fila: ");
    while(noAux){
        printf("%d ", noAux->valor);
        noAux = noAux->proximo;
    }
}

int main(){
    Fila fila = criarFila();
    int opcao, valor;
    tNo *noRemovido = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir elemento\n\t2 - Remover elemento\n\t3 - Visualizar Fila\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("Digite um valor para inserir na fila: ");
                scanf("%d", &valor);
                inserirNaFila(fila, valor);  
                break;
            case 2:
                noRemovido = removerNaFila(fila);
                printf("O elemento %d foi removido!", *noRemovido);
                break;
            case 3:
                imprimirFila(fila);
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