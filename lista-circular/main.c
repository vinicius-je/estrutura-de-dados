#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} tNo;

typedef struct{
    tNo *primeiro;
    tNo *ultimo;
    int tamanho;
} tcabec;

typedef tcabec *Lista;

Lista criarLista(){
    Lista lst = (Lista)malloc(sizeof(tcabec));
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    lst->tamanho = 0;
    return lst;
}

void inserirNoInicio(Lista lista, int num){
    tNo *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        novoNo->proximo = lista->primeiro;
        lista->primeiro = novoNo;
        if(lista->ultimo == NULL)
            lista->ultimo = novoNo;
        lista->ultimo->proximo = lista->primeiro;
        lista->tamanho++;
    }else{
        printf("Error: Não foi possivel alocar memoria!\n");
    }
}

void inserirNoFinal(Lista lista, int num){
    tNo *noAux, *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        // Verifica se a lista está vazia
        if(lista->primeiro == NULL){
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
            lista->ultimo->proximo = lista->primeiro;
        }
        else{
            lista->ultimo->proximo = novoNo;
            lista->ultimo = novoNo;
            novoNo->proximo = lista->primeiro;
        }    
        lista->tamanho++;
    }else{
        printf("Error: Não foi possível alocar memoria!\n");
    }
}

void inserirNoMeio(Lista lista, int num, int anterior){
    tNo *noAux, *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        // Verifica se a lista está vazia
        if(lista->primeiro == NULL){
            novoNo->proximo = NULL;
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
        }else{
            noAux = lista->primeiro;
            while(noAux->valor != anterior && noAux->proximo){
                noAux = noAux->proximo;
            }
            novoNo->proximo = noAux->proximo;
            noAux->proximo = novoNo;
        }    
        lista->tamanho++;
    }else{
        printf("Error: Não foi possível alocar memoria!\n");
    }
}

void imprimirLista(Lista lista){
    printf("\n\tLista: ");
    tNo *noAux = (tNo *)malloc(sizeof(tNo));

    noAux = lista->primeiro;

    if(noAux){
        do{
            printf("%d ", noAux->valor);
            noAux = noAux->proximo;
        }while(noAux != lista->primeiro);
    }
    printf("\n\n");
}

void removerElemento(Lista lista, int num){
    tNo *remover, *aux = NULL;

    if(lista->primeiro){
        if(lista->primeiro->valor == num && lista->primeiro->valor == lista->ultimo->valor){
            remover = lista->primeiro;
            lista->primeiro = NULL;
            lista->ultimo = NULL;
        }
        else if(lista->primeiro->valor == num){
            remover = lista->primeiro;
            lista->primeiro = remover->proximo;
            lista->ultimo->proximo = lista->primeiro;
        }
        else{
            aux = lista->primeiro;
            while(aux->proximo != lista->primeiro && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num){
                if(lista->ultimo == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->ultimo = aux;
                }else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
            }   
        }
    }
    lista->tamanho--;
}

int main(){
    int valor, opcao, anterior;
    Lista lista = criarLista();
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no meio\n\t4 - Remover um elemento\n\t5 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNoInicio(lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNoFinal(lista, valor);
            break;
        case 3:
            printf("Digite um valor e a referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserirNoMeio(lista, valor, anterior);
            break;
        case 4:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valor);
            removerElemento(lista, valor);
            break;
        case 5:
            imprimirLista(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}