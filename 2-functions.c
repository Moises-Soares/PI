// funcoes.c
// Este arquivo demonstra como declarar e utilizar funções em C

#include <stdio.h>

// Declaração de uma função que não retorna valor e não recebe parâmetros
void funcao_simples();

// Declaração de uma função que recebe parâmetros e retorna um valor
int soma(int a, int b);

// Declaração de uma função que recebe um array e seu tamanho como parâmetros
void imprime_array(int array[], int tamanho);

// Declaração de uma função recursiva
int fatorial(int n);

int main() {
    // Chamando uma função que não retorna valor e não recebe parâmetros
    funcao_simples();

    // Chamando uma função que recebe parâmetros e retorna um valor
    int resultado = soma(5, 3);
    printf("Resultado da soma: %d\n", resultado);

    // Criando um array e passando para uma função
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    imprime_array(numeros, tamanho);

    // Chamando uma função recursiva
    int numero = 5;
    int resultado_fatorial = fatorial(numero);
    printf("Fatorial de %d: %d\n", numero, resultado_fatorial);

    return 0;
}

// Definição de uma função que não retorna valor e não recebe parâmetros
void funcao_simples() {
    printf("Esta é uma função simples.\n");
}

// Definição de uma função que recebe parâmetros e retorna um valor
int soma(int a, int b) {
    return a + b;
}

// Definição de uma função que recebe um array e seu tamanho como parâmetros
void imprime_array(int array[], int tamanho) {
    printf("Elementos do array: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Definição de uma função recursiva
int fatorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}
