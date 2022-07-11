#include <stdio.h>
#include <stdlib.h>
// Biblioteca stdlib.h permite utilizar as funções malloc, free e sizeof...

int main(){
    int x;
    double y;

    //sizeof -> Permite calcular o tamanho de um determinado tipo de dado em bits.
    printf("tamanho da variavel x(int): %ld\n", sizeof(x));
    printf("tamanho da variavel y(double): %ld\n", sizeof(y));

    /* malloc -> solicita um bloco de memória(RAM) de tamanho definido pelo programador 
    e retorna um ponteiro para o endereço desse bloco de memória (tipo void*).*/
    int *p = (int *)malloc(sizeof(int));
    // atribui um valor para ser armazenado na memória alocada
    *p = 100;
    printf("valor na memoria alocada: %d\n", *p);

    /*o espaço de memória fica alocado até o programa chegar ao fim
    ou após o comando free(ponteiro) ser chamado*/

    // libera o espaço de memória
    free(p);

    printf("valor do ponteiro apos o free(): %d\n", *p);

    return 0;
}