#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
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

// Inserir elemento no inicio
void inserirNoInicio(Lista lista, int num){
    tNo *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        novoNo->proximo = lista->primeiro;
        novoNo->anterior = NULL;
        if(lista->primeiro == NULL){
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
        }

        if(lista->ultimo->anterior == NULL && lista->tamanho >= 1){
            lista->ultimo->anterior = novoNo;
        }
        lista->primeiro = novoNo;
        lista->tamanho++;
    }else{
        printf("Error: Não foi possivel alocar memoria!\n");
    }
}

void inserirNoFinal(Lista lista, int num){
    // Aloca espaço de memória para *noAux, *novoNo
    tNo *noAux, *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        novoNo->proximo = NULL;
        // Verifica se a lista está vazia
        if(lista->primeiro == NULL){
            novoNo->anterior = NULL;
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
        }
        else{
            noAux = lista->primeiro;
            // Loop para encontrar o último no
            while(noAux->proximo)
                noAux = noAux->proximo;
            // Insere o novoNo na ultima posição
            novoNo->anterior = noAux;
            noAux->proximo = novoNo;
            lista->ultimo = novoNo;
        }    
        lista->tamanho++;
    }else{
        printf("Error: Não foi possível alocar memoria!\n");
    }
}

void inserirNoMeio(Lista lista, int num, int anterior){
    // Aloca espaço de memória para *noAux, *novoNo
    tNo *noAux, *novoNo = (tNo *)malloc(sizeof(tNo));

    if(novoNo){
        novoNo->valor = num;
        // Verifica se a lista está vazia
        if(lista->primeiro == NULL){
            novoNo->proximo = NULL;
            novoNo->anterior = NULL;
            lista->primeiro = novoNo;
            lista->ultimo = novoNo;
        }else{
            noAux = lista->primeiro;
            while(noAux->valor != anterior && noAux->proximo){
                noAux = noAux->proximo;
            }
            novoNo->proximo = noAux->proximo;
            // Verifica se o noAux possui um próximo nó
            if(noAux->proximo)
                noAux->proximo->anterior = novoNo;
            else
                lista->ultimo = novoNo;
            novoNo->anterior = noAux;
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
    while(noAux){
        printf("%d ", noAux->valor);
        noAux = noAux->proximo;
    }
    printf("\n\n");
}

void removerElemento(Lista lista, int num){
    tNo *remover, *aux = NULL;

    if(lista){
        if(lista->primeiro->valor == num){
            remover = lista->primeiro;
            lista->primeiro = remover->proximo;
            if(lista->primeiro)
                lista->primeiro->anterior = NULL;
        }else{
            aux = lista->primeiro;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }   
        }
    }
    lista->tamanho--;
}

tNo* buscarElemento(Lista lista, int elemento){
    tNo *noAux = NULL;
    if(lista){
        noAux = lista->primeiro;
        while(noAux && noAux->valor != elemento)
            noAux = noAux->proximo;
    }
    return noAux;
}

void imprimirInverso(Lista lista){
    tNo *noAux = (tNo *)malloc(sizeof(tNo));
    noAux = lista->ultimo;
    printf("Lista Invertida: ");
    while (noAux->anterior){
        printf("%d ", noAux->valor);
        noAux = noAux->anterior;
    }
    printf("%d ", noAux->valor);
    printf("\n\n");
}

int main(){
    int valor, opcao, anterior;
    Lista lista = criarLista();
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir no inicio\n\t2 - Inserir no final\n\t3 - Inserir no meio\n\t4 - Remover um elemento\n\t5 - Buscar elemento\n\t6 - Imprimir\n\t7 - Imprimir Invertido\n\n");
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
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            tNo *busca = buscarElemento(lista, valor);
            if(busca)
                printf("Elemento %d foi encontrado\n\n", busca->valor);
            else
                printf("Elemento nao econtrado!\n\n");
            break;
        case 6:
            imprimirLista(lista);
            break;
        case 7:
            imprimirInverso(lista);
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n\n");
            break;
        }
    }while(opcao != 0);

    return 0;
}