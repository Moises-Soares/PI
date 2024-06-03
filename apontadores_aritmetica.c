// aritmetica_ponteiros.c
// Este arquivo demonstra a aritmética de ponteiros em C

#include <stdio.h>

int main() {
    // Declaração e inicialização de um array
    int array[5] = {10, 20, 30, 40, 50};
    int *ponteiro;

    // Inicializando o ponteiro com o endereço do primeiro elemento do array
    ponteiro = array;

    // Acessando elementos do array usando aritmética de ponteiros
    printf("Acessando elementos do array usando aritmética de ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("array[%d] = %d usando ponteiro %p\n", i, *(ponteiro + i), (ponteiro + i));
    }

    // Incrementando ponteiros
    ponteiro = array; // Reinicializando ponteiro para o início do array
    printf("\nIncrementando ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor: %d, Endereço: %p\n", *ponteiro, ponteiro);
        ponteiro++; // Incrementa o ponteiro para apontar para o próximo elemento
    }

    // Decrementando ponteiros
    ponteiro--; // Ajustando ponteiro para o último elemento
    printf("\nDecrementando ponteiros:\n");
    for (int i = 0; i < 5; i++) {
        printf("Valor: %d, Endereço: %p\n", *ponteiro, ponteiro);
        ponteiro--; // Decrementa o ponteiro para apontar para o elemento anterior
    }

    // Diferenca entre dois ponteiros
    int *ponteiro_inicio = &array[0];
    int *ponteiro_fim = &array[4];
    int diferenca = ponteiro_fim - ponteiro_inicio;
    printf("\nDiferença entre dois ponteiros: %d\n", diferenca);

    return 0;
}
