#include <stdio.h>
#include <string.h>

// Definição da estrutura Aluno
typedef struct aluno {
    int numero;             // Número do aluno
    char nome[100];         // Nome do aluno
    int miniT[6];           // Notas dos mini testes
    float teste;            // Nota do teste final
} Aluno;

// Função para calcular a nota de um aluno
int nota(Aluno a) {
    int i;
    int sumMiniT = 0;

    // Soma das notas dos mini testes
    for (i = 0; i < 6; i++) {
        sumMiniT += a.miniT[i];
    }

    // Cálculo da nota final
    float finalNota = (float)sumMiniT / 6 * 0.3 + a.teste * 0.7;
    // Retorna 0 se a nota final for menor que 9.5, caso contrário, arredonda a nota
    return (finalNota >= 9.5) ? (int)(finalNota + 0.5) : 0;
}

// Função para procurar o número de um aluno em um array ordenado
int procuraNum(int num, Aluno t[], int N) {
    int left = 0, right = N - 1;

    // Busca binária
    while (left <= right) {
        int mid = (left + right) / 2;
        if (t[mid].numero == num) {
            return mid;  // Retorna o índice se o número for encontrado
        } else if (t[mid].numero < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Retorna -1 se o número não for encontrado
}

// Função para ordenar alunos por número
void ordenaPorNum(Aluno t[], int N) {
    int i, j;

    // Algoritmo de ordenação por seleção
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (t[i].numero > t[j].numero) {
                // Troca os elementos
                Aluno temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

// Função para criar um vetor de índices ordenado por número
void criaIndPorNum(Aluno t[], int N, int ind[]) {
    int i, j;

    // Inicializa o vetor de índices
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }

    // Ordena os índices com base nos números dos alunos
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (t[ind[i]].numero > t[ind[j]].numero) {
                // Troca os índices
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }
}

// Função para imprimir turma
void imprimeTurma(int ind[], Aluno t[], int N) {
    int i;

    // Imprime os alunos na ordem definida pelo vetor de índices
    for (i = 0; i < N; i++) {
        Aluno a = t[ind[i]];
        printf("Numero: %d, Nome: %s, Nota: %d\n", a.numero, a.nome, nota(a));
    }
}

// Função adaptada para procurar número usando vetor de índices
int procuraNumInd(int num, Aluno t[], int ind[], int N) {
    int left = 0, right = N - 1;

    // Busca binária usando o vetor de índices
    while (left <= right) {
        int mid = (left + right) / 2;
        if (t[ind[mid]].numero == num) {
            return ind[mid];  // Retorna o índice se o número for encontrado
        } else if (t[ind[mid]].numero < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Retorna -1 se o número não for encontrado
}

// Função para criar um vetor de índices ordenado por nome
void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int i, j;

    // Inicializa o vetor de índices
    for (i = 0; i < N; i++) {
        ind[i] = i;
    }

    // Ordena os índices com base nos nomes dos alunos
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if (strcmp(t[ind[i]].nome, t[ind[j]].nome) > 0) {
                // Troca os índices
                int temp = ind[i];
                ind[i] = ind[j];
                ind[j] = temp;
            }
        }
    }
}

int main() {
    // Exemplo de uso das funções
    Aluno turma[] = {
        {4444, "Andre", {2, 1, 0, 2, 2, 2}, 10.5},
        {2222, "Joana", {2, 2, 2, 1, 0, 0}, 14.5},
        {7777, "Maria", {2, 2, 2, 2, 2, 1}, 18.5},
        {3333, "Paulo", {0, 0, 2, 2, 2, 1}, 8.7}
    };
    int N = 4;
    int ind[N];

    // Teste das funções

    // Cria vetor de índices ordenado por número
    criaIndPorNum(turma, N, ind);
    printf("Turma ordenada por número:\n");
    imprimeTurma(ind, turma, N);

    // Cria vetor de índices ordenado por nome
    criaIndPorNome(turma, N, ind);
    printf("Turma ordenada por nome:\n");
    imprimeTurma(ind, turma, N);

    return 0;
}


// Porposta de exercicios
// 1. Implemente uma função que calcula a média das notas dos mini testes de uma turma.
// 2. Crie uma função que verifica se um aluno foi aprovado ou reprovado, considerando que a nota de aprovação é 9.5.