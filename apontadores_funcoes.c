// ponteiros_funcoes_tutorial.c
// Este arquivo demonstra como declarar e utilizar ponteiros em C, incluindo seu uso em funções

#include <stdio.h>

// Função que recebe um ponteiro como argumento e modifica o valor apontado
void modifica_valor(int *ptr) {
    *ptr = 50;
}

// Função que troca os valores de dois inteiros usando ponteiros
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que retorna um ponteiro para um array de inteiros
int* cria_array(int tamanho) {
    int *array = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        array[i] = i * 10;
    }
    return array;
}

int main() {
    // Declaração de uma variável inteira
    int var = 10;
    int *ponteiro = &var;

    // Utilização de ponteiros em funções
    printf("Valor inicial de var: %d\n", var);
    modifica_valor(ponteiro);
    printf("Valor de var após chamar modifica_valor: %d\n", var);

    // Troca de valores usando ponteiros
    int x = 5, y = 10;
    printf("Valores antes da troca: x = %d, y = %d\n", x, y);
    troca(&x, &y);
    printf("Valores após a troca: x = %d, y = %d\n", x, y);

    // Uso de função que retorna um ponteiro
    int tamanho = 5;
    int *array = cria_array(tamanho);
    printf("Array criado pela função cria_array:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Liberar a memória alocada para o array
    free(array);

    return 0;
}
