/*
 * Introdução Teórica
 *
 * Neste ficheiro, abordaremos conceitos fundamentais de programação em C com ênfase na manipulação de arrays e ponteiros.
 * Arrays são estruturas de dados que armazenam elementos do mesmo tipo em posições contíguas na memória, permitindo acesso rápido e eficiente aos dados.
 * Ponteiros são variáveis que armazenam endereços de memória e são extremamente úteis para manipulação de arrays e alocação dinâmica de memória.
 * A combinação destes dois conceitos é poderosa e frequentemente utilizada em programação de baixo nível para otimização de desempenho.
 */

#include <stdio.h>

// Exercício 1(a)
void exercicio1a() {
    int x[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *y, *z, i;
    y = x;
    z = x + 3;
    for (i = 0; i < 5; i++) {
        printf("%d %d %d\n", x[i], *y, *z);
        y = y + 1;
        z = z + 2;
    }
}

// Exercício 1(b)
void exercicio1b() {
    int i, j, *a, *b;
    i = 3;
    j = 5;
    a = b = (int *)42;
    a = &i;
    b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf("%d\n", j);
}

// Exercício 2
void swapM(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Exercício 3
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// Exercício 4
int soma(int v[], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
    }
    return sum;
}

// Exercício 5
void inverteArray(int v[], int N) {
    for (int i = 0; i < N / 2; i++) {
        swap(v, i, N - i - 1);
    }
}

// Exercício 6
int maximum(int v[], int N, int *m) {
    if (N <= 0) return 1;
    *m = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] > *m) {
            *m = v[i];
        }
    }
    return 0;
}

// Exercício 7
void quadrados(int q[], int N) {
    for (int i = 0; i < N; i++) {
        q[i] = i * i;
    }
}

// Exercício 8
void pascal(int v[], int N) {
    v[0] = 1;
    for (int i = 1; i < N; i++) {
        v[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            v[j] = v[j] + v[j - 1];
        }
    }
}

// Adaptação do Exercício 8(b)
void imprimePascal(int N) {
    int linha[N];
    for (int i = 1; i <= N; i++) {
        pascal(linha, i);
        for (int j = 0; j < i; j++) {
            printf("%d ", linha[j]);
        }
        printf("\n");
    }
}

// Função principal para executar os exercícios
int main() {
    printf("Exercício 1(a):\n");
    exercicio1a();
    printf("\nExercício 1(b):\n");
    exercicio1b();
    
    int x = 3, y = 5;
    printf("\nExercício 2:\n");
    printf("Antes de swapM: x = %d, y = %d\n", x, y);
    swapM(&x, &y);
    printf("Depois de swapM: x = %d, y = %d\n", x, y);
    
    int v[] = {1, 2, 3, 4, 5};
    printf("\nExercício 3:\n");
    printf("Antes de swap: v[1] = %d, v[3] = %d\n", v[1], v[3]);
    swap(v, 1, 3);
    printf("Depois de swap: v[1] = %d, v[3] = %d\n", v[1], v[3]);

    printf("\nExercício 4:\n");
    printf("Soma do array: %d\n", soma(v, 5));

    printf("\nExercício 5:\n");
    printf("Array antes de inverteArray: ");
    for (int i = 0; i < 5; i++) printf("%d ", v[i]);
    printf("\n");
    inverteArray(v, 5);
    printf("Array depois de inverteArray: ");
    for (int i = 0; i < 5; i++) printf("%d ", v[i]);
    printf("\n");

    int max;
    printf("\nExercício 6:\n");
    if (maximum(v, 5, &max) == 0) {
        printf("Máximo do array: %d\n", max);
    } else {
        printf("Erro ao calcular o máximo.\n");
    }

    int q[5];
    printf("\nExercício 7:\n");
    quadrados(q, 5);
    printf("Quadrados dos primeiros 5 números naturais: ");
    for (int i = 0; i < 5; i++) printf("%d ", q[i]);
    printf("\n");

    printf("\nExercício 8:\n");
    int linha[5];
    pascal(linha, 5);
    printf("5ª linha do triângulo de Pascal: ");
    for (int i = 0; i < 5; i++) printf("%d ", linha[i]);
    printf("\n");

    printf("\nAdaptação do Exercício 8(b):\n");
    imprimePascal(5);

    return 0;
}

/*
 * Exercícios Adicionais
 *
 * 9. Defina uma função int findIndex(int v[], int N, int value) que retorna o índice do primeiro
 *    elemento igual a value no array v. Se o valor não estiver presente, retorne -1.
 */
int findIndex(int v[], int N, int value) {
    for (int i = 0; i < N; i++) {
        if (v[i] == value) {
            return i;
        }
    }
    return -1;
}

/*
 * 10. Defina uma função void merge(int a[], int b[], int c[], int Na, int Nb) que preenche o array c
 *     com os elementos dos arrays a e b, mantendo a ordem dos elementos.
 */
void merge(int a[], int b[], int c[], int Na, int Nb) {
    int i = 0, j = 0, k = 0;
    while (i < Na && j < Nb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < Na) {
        c[k++] = a[i++];
    }
    while (j < Nb) {
        c[k++] = b[j++];
    }
}
