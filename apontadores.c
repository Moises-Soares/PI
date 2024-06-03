// ponteiros_tutorial.c
// Este arquivo demonstra como declarar e utilizar ponteiros em C

#include <stdio.h>

int main() {
    // Declaração de uma variável inteira
    int var = 10;
    // Declaração de um ponteiro para inteiro
    int *ponteiro;

    // Inicializando o ponteiro com o endereço da variável var
    ponteiro = &var;

    // Acessando o valor da variável var usando o ponteiro
    printf("Valor da variável var: %d\n", var);
    printf("Valor da variável var acessado através do ponteiro: %d\n", *ponteiro);

    // Acessando o endereço da variável var
    printf("Endereço da variável var: %p\n", (void *)&var);
    printf("Endereço armazenado no ponteiro: %p\n", (void *)ponteiro);

    // Modificando o valor da variável var usando o ponteiro
    *ponteiro = 20;
    printf("Novo valor da variável var após modificação via ponteiro: %d\n", var);

    // Ponteiros e arrays
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr_array = array; // Inicializando o ponteiro com o endereço do primeiro elemento do array

    // Acessando elementos do array usando o ponteiro
    printf("Elementos do array acessados via ponteiro:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr_array + i));
    }
    printf("\n");

    // Ponteiros para ponteiros
    int **ponteiro_para_ponteiro = &ponteiro;
    printf("Valor do ponteiro armazenado no ponteiro para ponteiro: %p\n", (void *)*ponteiro_para_ponteiro);
    printf("Valor da variável var acessado através do ponteiro para ponteiro: %d\n", **ponteiro_para_ponteiro);

    // Ponteiros void
    void *ponteiro_void;
    ponteiro_void = &var;
    printf("Valor da variável var acessado através de um ponteiro void: %d\n", *(int *)ponteiro_void);

    return 0;
}
