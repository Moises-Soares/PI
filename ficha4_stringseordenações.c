#include <stdio.h>
#include <string.h>

// Função que conta o número de vogais em uma string
int contaVogais(char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            count++;
        }
    }
    return count;
}

// Função que remove repetições consecutivas de vogais em uma string usando um array auxiliar
int retiraVogaisRep(char *s) {
    char aux[strlen(s) + 1];
    int j = 0, removed = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", s[i]) && s[i] == s[i + 1]) {
            removed++;
            continue;
        }
        aux[j++] = s[i];
    }
    aux[j] = '\0';
    strcpy(s, aux);
    
    return removed;
}

// Função que duplica todas as vogais de uma string usando um array auxiliar
int duplicaVogais(char *s) {
    int len = strlen(s);
    char aux[2 * len + 1];
    int j = 0, added = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        aux[j++] = s[i];
        if (strchr("aeiouAEIOU", s[i])) {
            aux[j++] = s[i];
            added++;
        }
    }
    aux[j] = '\0';
    strcpy(s, aux);
    
    return added;
}

// Função que verifica se um array de inteiros está ordenado em ordem crescente
int ordenado(int v[], int N) {
    for (int i = 1; i < N; i++) {
        if (v[i-1] > v[i]) {
            return 0;
        }
    }
    return 1;
}

// Função que mescla dois arrays ordenados em um único array ordenado
void merge(int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0, k = 0;
    
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            r[k++] = a[i++];
        } else {
            r[k++] = b[j++];
        }
    }
    
    while (i < na) {
        r[k++] = a[i++];
    }
    
    while (j < nb) {
        r[k++] = b[j++];
    }
}

// Função que particiona um array em dois segmentos com base em um valor x
int partition(int v[], int N, int x) {
    int aux[N];
    int j = 0, count = 0;
    
    for (int i = 0; i < N; i++) {
        if (v[i] <= x) {
            aux[j++] = v[i];
            count++;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (v[i] > x) {
            aux[j++] = v[i];
        }
    }
    
    memcpy(v, aux, N * sizeof(int));
    return count;
}

int main() {
    // Testando funções sobre strings
    char str1[] = "Hello World";
    printf("Number of vowels: %d\n", contaVogais(str1));
    
    char str2[] = "Estaa e umaa string coom duuuplicadoos";
    printf("Removed vowels: %d\n", retiraVogaisRep(str2));
    printf("String after removal: %s\n", str2);
    
    char str3[] = "Hello";
    printf("Added characters: %d\n", duplicaVogais(str3));
    printf("String after duplication: %s\n", str3);
    
    // Testando funções sobre arrays ordenados
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 3, 2, 5, 4};
    printf("Array 1 is ordered: %d\n", ordenado(arr1, 5));
    printf("Array 2 is ordered: %d\n", ordenado(arr2, 5));
    
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int r[6];
    merge(a, 3, b, 3, r);
    printf("Merged array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
    
    int arr3[] = {9, 4, 6, 2, 7, 5, 1};
    int pos = partition(arr3, 7, 5);
    printf("Partitioned array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    printf("Number of elements <= 5: %d\n", pos);
    
    return 0;
}

/*
Exercícios Adicionais:

1. Função para encontrar a maior palavra em uma string:
   - Defina uma função `char* maiorPalavra(char *s)` que retorna a maior palavra em uma string (considerando palavras como sequências de caracteres alfanuméricos separados por espaços).

2. Função para ordenar um array de strings:
   - Defina uma função `void ordenaStrings(char *arr[], int n)` que ordena um array de strings em ordem alfabética.
*/
