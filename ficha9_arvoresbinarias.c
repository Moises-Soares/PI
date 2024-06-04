#include <stdio.h>
#include <stdlib.h>

// Definição de ABin
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

// Função para criar um novo ABin
ABin newABin(int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if (a != NULL) {
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

// Funções sobre árvores binárias

// (a) Calcula a altura de uma árvore
int altura(ABin a) {
    if (a == NULL) return 0;
    int esq = altura(a->esq);
    int dir = altura(a->dir);
    return 1 + (esq > dir ? esq : dir);
}

// (b) Calcula o número de folhas
int nFolhas(ABin a) {
    if (a == NULL) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return nFolhas(a->esq) + nFolhas(a->dir);
}

// (c) Calcula o nodo mais à esquerda de uma árvore
ABin maisEsquerda(ABin a) {
    if (a == NULL) return NULL;
    while (a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

// (d) Imprime os elementos de uma árvore no nível l
void imprimeNivel(ABin a, int l) {
    if (a == NULL) return;
    if (l == 0) {
        printf("%d ", a->valor);
    } else {
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);
    }
}

// (e) Testa se x ocorre na árvore
int procuraE(ABin a, int x) {
    if (a == NULL) return 0;
    if (a->valor == x) return 1;
    return procuraE(a->esq, x) || procuraE(a->dir, x);
}

// Funções sobre árvores binárias de procura

// (f) Procura um elemento numa árvore binária de procura
struct nodo *procura(ABin a, int x) {
    if (a == NULL) return NULL;
    if (a->valor == x) return a;
    if (x < a->valor) return procura(a->esq, x);
    return procura(a->dir, x);
}

// (g) Calcula o nível a que o elemento ocorre na árvore
int nivel(ABin a, int x) {
    if (a == NULL) return -1;
    if (a->valor == x) return 0;
    int n = (x < a->valor) ? nivel(a->esq, x) : nivel(a->dir, x);
    return (n == -1) ? -1 : 1 + n;
}

// (h) Imprime elementos da árvore menores do que um dado valor
void imprimeAte(ABin a, int x) {
    if (a == NULL) return;
    if (a->valor < x) {
        imprimeAte(a->esq, x);
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    } else {
        imprimeAte(a->esq, x);
    }
}

/*
Sugestões de exercícios:

1. Implemente uma função que conte o número de nós em uma árvore binária. A função deve ter a seguinte assinatura:
   int contaNos(ABin a);

2. Implemente uma função que verifique se uma árvore binária é balanceada. A função deve ter a seguinte assinatura:
   int ehBalanceada(ABin a);
*/

int main() {
    // Criando uma árvore binária de exemplo
    ABin a = newABin(10, 
                     newABin(5, newABin(2, NULL, NULL), newABin(7, NULL, NULL)),
                     newABin(15, newABin(12, NULL, NULL), newABin(20, NULL, NULL)));

    // Testando a função altura
    printf("Altura: %d\n", altura(a)); // Esperado: 3

    // Testando a função nFolhas
    printf("Número de folhas: %d\n", nFolhas(a)); // Esperado: 4

    // Testando a função maisEsquerda
    ABin esq = maisEsquerda(a);
    if (esq != NULL) {
        printf("Nodo mais à esquerda: %d\n", esq->valor); // Esperado: 2
    } else {
        printf("Árvore vazia\n");
    }

    // Testando a função imprimeNivel
    printf("Elementos no nível 2: ");
    imprimeNivel(a, 2); // Esperado: 2 7 12 20
    printf("\n");

    // Testando a função procuraE
    printf("Procurando 7: %d\n", procuraE(a, 7)); // Esperado: 1
    printf("Procurando 9: %d\n", procuraE(a, 9)); // Esperado: 0

    // Testando a função procura
    ABin p = procura(a, 12);
    if (p != NULL) {
        printf("Elemento encontrado: %d\n", p->valor); // Esperado: 12
    } else {
        printf("Elemento não encontrado\n");
    }

    // Testando a função nivel
    printf("Nível do elemento 7: %d\n", nivel(a, 7)); // Esperado: 2
    printf("Nível do elemento 9: %d\n", nivel(a, 9)); // Esperado: -1

    // Testando a função imprimeAte
    printf("Elementos menores que 15: ");
    imprimeAte(a, 15); // Esperado: 2 5 7 10 12
    printf("\n");

    return 0;
}