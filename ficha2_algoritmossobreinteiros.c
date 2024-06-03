/*
 * Ficha 2 - Programação Imperativa
 * Algoritmos Numéricos sobre Inteiros
 *
 * Introdução Teórica:
 * Nesta ficha, exploramos diversos algoritmos numéricos que operam sobre inteiros. 
 * Discutiremos a implementação de funções para multiplicação, cálculo do máximo divisor comum (MDC),
 * e a sequência de Fibonacci, utilizando diferentes abordagens para melhorar a eficiência dos algoritmos.
 * 
 * Resolução com Explicação Detalhada:
 */

#include <stdio.h>

// 1. Multiplicação utilizando somas sucessivas
float multInt1(int n, float m) {
    float r = 0;
    for (int i = 0; i < n; i++) {
        r += m;
    }
    return r;
}

// 2. Multiplicação utilizando o método russo (baseado na representação binária)
float multInt2(int n, float m, int *opCount) {
    float result = 0;
    *opCount = 0;
    while (n > 0) {
        if (n % 2 != 0) {
            result += m;
            (*opCount)++;
        }
        n /= 2;
        m *= 2;
        (*opCount)++;
    }
    return result;
}

// 3. Máximo divisor comum (MDC) por força bruta
int mdc1(int a, int b) {
    int divisor = (a < b) ? a : b;
    while (divisor > 0) {
        if (a % divisor == 0 && b % divisor == 0) {
            return divisor;
        }
        divisor--;
    }
    return 1;
}

// 4. Máximo divisor comum (MDC) utilizando o algoritmo de Euclides
int mdc2(int a, int b, int *iterCount) {
    *iterCount = 0;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
        (*iterCount)++;
    }
    return a;
}

// 5. Máximo divisor comum (MDC) utilizando o algoritmo de Euclides com mod
int mdc3(int a, int b, int *iterCount) {
    *iterCount = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        (*iterCount)++;
    }
    return a;
}

// 6. Sequência de Fibonacci (recursiva)
int fib1(int n) {
    if (n < 2) {
        return 1;
    }
    return fib1(n - 1) + fib1(n - 2);
}

// 7. Sequência de Fibonacci (iterativa)
int fib2(int n) {
    if (n < 2) {
        return 1;
    }
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/*
 * Proposta de Exercícios:
 *
 * 1. Implemente uma função que calcula o mínimo múltiplo comum (MMC) de dois números inteiros.
 * 2. Crie uma função que verifica se um número é primo.
 */

int main() {
    // Testes das funções implementadas
    printf("MultInt1(5, 3.5) = %f\n", multInt1(5, 3.5));

    int opCount;
    printf("MultInt2(5, 3.5, &opCount) = %f, Operações: %d\n", multInt2(5, 3.5, &opCount), opCount);

    printf("MDC1(45, 30) = %d\n", mdc1(45, 30));

    int iterCount;
    printf("MDC2(45, 30, &iterCount) = %d, Iterações: %d\n", mdc2(45, 30, &iterCount), iterCount);

    printf("MDC3(45, 30, &iterCount) = %d, Iterações: %d\n", mdc3(45, 30, &iterCount), iterCount);

    printf("Fib1(10) = %d\n", fib1(10));
    printf("Fib2(10) = %d\n", fib2(10));

    return 0;
}
