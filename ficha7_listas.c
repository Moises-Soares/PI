#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista ligada
typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula *prox;
} *Palavras;

/*
 * Teoria dos Apontadores:
 * 
 * Apontadores são variáveis que armazenam endereços de memória. Em C, eles são
 * amplamente usados para manipular estruturas dinâmicas de dados, como listas ligadas.
 * Um apontador é declarado usando o símbolo '*', e a operação de obtenção do endereço de uma
 * variável é feita usando o operador '&'.
 * 
 * Exemplo:
 * int x = 10;
 * int *p = &x; // 'p' agora armazena o endereço de 'x'
 * 
 * Em estruturas de dados como listas ligadas, apontadores são usados para conectar os nós (ou células).
 * Cada nó contém um dado (neste caso, uma palavra e um contador de ocorrências) e um apontador para o próximo nó.
 */

/*
 * Teoria de Alocação e Liberação de Memória:
 * 
 * Em C, a alocação de memória dinâmica é feita usando as funções malloc, calloc e realloc.
 * - malloc(size): Aloca 'size' bytes de memória e retorna um apontador para o início do espaço alocado.
 *   A memória alocada contém lixo, ou seja, valores indefinidos.
 * 
 * - calloc(n, size): Aloca espaço para 'n' elementos, cada um com 'size' bytes, e inicializa todos os bytes com zero.
 * 
 * - realloc(ptr, size): Redimensiona o espaço de memória alocado anteriormente apontado por 'ptr' para 'size' bytes.
 * 
 * A liberação da memória alocada dinamicamente é feita usando a função free(ptr), que libera o espaço apontado por 'ptr'.
 * 
 * Exemplos:
 * int *p = (int *)malloc(10 * sizeof(int)); // Aloca memória para 10 inteiros
 * free(p); // Libera a memória alocada
 * 
 * A alocação dinâmica é crucial para estruturas de dados como listas ligadas, onde o tamanho da estrutura pode variar em tempo de execução.
 */

// 1. Função que liberta todo o espaço da heap ocupado pela lista de palavras
void libertaLista(Palavras l) {
    Palavras temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp->palavra);  // Libera a memória alocada para a palavra
        free(temp);           // Libera a memória alocada para a célula
    }
}

// 2. Função que calcula quantas palavras (diferentes) existem armazenadas
int quantasP(Palavras l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }
    return count;
}

// 3. Função que escreve no ecrã, uma por linha, todas as palavras armazenadas, bem como o número de ocorrências
void listaPal(Palavras l) {
    while (l != NULL) {
        printf("%s: %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// 4. Função que determina qual a última palavra da lista
char *ultima(Palavras l) {
    if (l == NULL) return NULL;
    while (l->prox != NULL) {
        l = l->prox;
    }
    return l->palavra;
}

// 5. Função que acrescenta uma palavra no início da lista (com 1 como número de ocorrências)
Palavras acrescentaInicio(Palavras l, char *p) {
    Palavras nova = (Palavras) malloc(sizeof(struct celula));
    nova->palavra = strdup(p);
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

// 6. Função que acrescenta uma palavra no fim da lista (com 1 como número de ocorrências)
Palavras acrescentaFim(Palavras l, char *p) {
    Palavras nova = (Palavras) malloc(sizeof(struct celula));
    nova->palavra = strdup(p);
    nova->ocorr = 1;
    nova->prox = NULL;
    if (l == NULL) return nova;
    Palavras temp = l;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = nova;
    return l;
}

// 7. Função que regista mais uma ocorrência da palavra p. Se a palavra já existir, o número de ocorrências deve ser incrementado. No outro caso deve ser inserida uma nova célula.
Palavras acrescenta(Palavras l, char *p) {
    Palavras temp = l;
    while (temp != NULL) {
        if (strcmp(temp->palavra, p) == 0) {
            temp->ocorr++;
            return l;
        }
        temp = temp->prox;
    }
    // Se a palavra não for encontrada, insere no início
    return acrescentaInicio(l, p);
}

// 8. Função que calcula a célula correspondente à palavra mais frequente
struct celula *maisFreq(Palavras l) {
    if (l == NULL) return NULL;
    Palavras maisFreq = l;
    l = l->prox;
    while (l != NULL) {
        if (l->ocorr > maisFreq->ocorr) {
            maisFreq = l;
        }
        l = l->prox;
    }
    return maisFreq;
}

int main() {
    // Exemplo de uso das funções

    // Criando uma lista de palavras
    Palavras lista = NULL;
    lista = acrescentaInicio(lista, "palavra1");
    lista = acrescentaFim(lista, "palavra2");
    lista = acrescenta(lista, "palavra1");  // Incrementa ocorrência de "palavra1"
    lista = acrescenta(lista, "palavra3");

    // Listando todas as palavras e suas ocorrências
    printf("Lista de palavras:\n");
    listaPal(lista);

    // Mostrando a última palavra da lista
    printf("\nÚltima palavra: %s\n", ultima(lista));

    // Contando o número de palavras diferentes
    printf("\nNúmero de palavras diferentes: %d\n", quantasP(lista));

    // Encontrando a palavra mais frequente
    Palavras maisFrequente = maisFreq(lista);
    if (maisFrequente != NULL) {
        printf("\nPalavra mais frequente: %s (%d ocorrências)\n", maisFrequente->palavra, maisFrequente->ocorr);
    }

    // Liberando a lista
    libertaLista(lista);

    return 0;
}

/*
 * Exercícios para Treinar
 * 
 * 1. Escreva uma função que remova todas as ocorrências de uma determinada palavra da lista.
 * 
 *    Função: Palavras removePalavra(Palavras l, char *p);
 *    - Esta função deve percorrer a lista, encontrar todas as ocorrências da palavra 'p' e removê-las.
 *    - A memória alocada para as palavras removidas deve ser liberada.
 * 
 * 2. Escreva uma função que ordene a lista de palavras em ordem alfabética.
 * 
 *    Função: Palavras ordenaLista(Palavras l);
 *    - Esta função deve reordenar os nós da lista para que as palavras fiquem em ordem alfabética.
 *    - Você pode usar qualquer algoritmo de ordenação, mas certifique-se de que ele funciona para listas ligadas.
 */
