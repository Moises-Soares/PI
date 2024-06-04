#include <stdio.h>
#include <stdlib.h>

#define Max 100

// Definição da estrutura para uma stack estática
typedef struct staticStack {
    int sp;           // Índice do topo da stack
    int values[Max];  // Array para armazenar os valores da stack
} STACK, *SStack;

// Inicializa uma stack como vazia
void SinitStack(SStack s) {
    s->sp = -1;
}

// Testa se uma stack está vazia
int SisEmpty(SStack s) {
    return s->sp == -1;
}

// Acrescenta um elemento ao topo da stack
int Spush(SStack s, int x) {
    if (s->sp < Max - 1) {
        s->values[++(s->sp)] = x;
        return 0;  // Sucesso
    } else {
        return 1;  // Stack cheia
    }
}

// Remove o elemento do topo da stack
int Spop(SStack s, int *x) {
    if (SisEmpty(s)) {
        return 1;  // Stack vazia
    } else {
        *x = s->values[(s->sp)--];
        return 0;  // Sucesso
    }
}

// Obtém o elemento do topo da stack sem removê-lo
int Stop(SStack s, int *x) {
    if (SisEmpty(s)) {
        return 1;  // Stack vazia
    } else {
        *x = s->values[s->sp];
        return 0;  // Sucesso
    }
}

// Definição da estrutura para uma queue estática
typedef struct staticQueue {
    int front;       // Índice do início da queue
    int length;      // Comprimento da queue
    int values[Max]; // Array para armazenar os valores da queue
} QUEUE, *SQueue;

// Inicializa uma queue como vazia
void SinitQueue(SQueue q) {
    q->front = 0;
    q->length = 0;
}

// Testa se uma queue está vazia
int SisEmptyQ(SQueue q) {
    return q->length == 0;
}

// Acrescenta um elemento ao fim da queue
int Senqueue(SQueue q, int x) {
    if (q->length < Max) {
        q->values[(q->front + q->length) % Max] = x;
        q->length++;
        return 0;  // Sucesso
    } else {
        return 1;  // Queue cheia
    }
}

// Remove o elemento do início da queue
int Sdequeue(SQueue q, int *x) {
    if (SisEmptyQ(q)) {
        return 1;  // Queue vazia
    } else {
        *x = q->values[q->front];
        q->front = (q->front + 1) % Max;
        q->length--;
        return 0;  // Sucesso
    }
}

// Obtém o elemento do início da queue sem removê-lo
int Sfront(SQueue q, int *x) {
    if (SisEmptyQ(q)) {
        return 1;  // Queue vazia
    } else {
        *x = q->values[q->front];
        return 0;  // Sucesso
    }
}

// Definição da estrutura para uma stack dinâmica
typedef struct dinStack {
    int size;    // Tamanho do array values
    int sp;      // Índice do topo da stack
    int *values; // Array dinâmico para armazenar os valores da stack
} *DStack;

// Inicializa uma stack dinâmica
void DinitStack(DStack s) {
    s->size = Max;
    s->sp = -1;
    s->values = (int *)malloc(Max * sizeof(int));
}

// Libera a memória da stack dinâmica
void DfreeStack(DStack s) {
    free(s->values);
}

// Acrescenta um elemento ao topo da stack dinâmica
int Dpush(DStack s, int x) {
    if (s->sp == s->size - 1) {
        s->size *= 2;
        s->values = (int *)realloc(s->values, s->size * sizeof(int));
    }
    s->values[++(s->sp)] = x;
    return 0;  // Sucesso
}

// Remove o elemento do topo da stack dinâmica
int Dpop(DStack s, int *x) {
    if (s->sp == -1) {
        return 1;  // Stack vazia
    } else {
        *x = s->values[(s->sp)--];
        return 0;  // Sucesso
    }
}

// Definição da estrutura para uma queue dinâmica
typedef struct dinQueue {
    int size;    // Tamanho do array values
    int front;   // Índice do início da queue
    int length;  // Comprimento da queue
    int *values; // Array dinâmico para armazenar os valores da queue
} *DQueue;

// Inicializa uma queue dinâmica
void DinitQueue(DQueue q) {
    q->size = Max;
    q->front = 0;
    q->length = 0;
    q->values = (int *)malloc(Max * sizeof(int));
}

// Libera a memória da queue dinâmica
void DfreeQueue(DQueue q) {
    free(q->values);
}

// Acrescenta um elemento ao fim da queue dinâmica
int Denqueue(DQueue q, int x) {
    if (q->length == q->size) {
        q->size *= 2;
        q->values = (int *)realloc(q->values, q->size * sizeof(int));
    }
    q->values[(q->front + q->length) % q->size] = x;
    q->length++;
    return 0;  // Sucesso
}

// Remove o elemento do início da queue dinâmica
int Ddequeue(DQueue q, int *x) {
    if (q->length == 0) {
        return 1;  // Queue vazia
    } else {
        *x = q->values[q->front];
        q->front = (q->front + 1) % q->size;
        q->length--;
        return 0;  // Sucesso
    }
}

// Função principal para testes
int main() {
    // Testes com stack estática
    struct staticStack ss;
    SinitStack(&ss);
    Spush(&ss, 10);
    Spush(&ss, 20);
    int x;
    Spop(&ss, &x);
    printf("Elemento retirado da stack estática: %d\n", x);

    // Testes com queue estática
    struct staticQueue sq;
    SinitQueue(&sq);
    Senqueue(&sq, 30);
    Senqueue(&sq, 40);
    Sdequeue(&sq, &x);
    printf("Elemento retirado da queue estática: %d\n", x);

    // Testes com stack dinâmica
    DStack ds = (DStack)malloc(sizeof(struct dinStack));
    DinitStack(ds);
    Dpush(ds, 50);
    Dpush(ds, 60);
    Dpop(ds, &x);
    printf("Elemento retirado da stack dinâmica: %d\n", x);
    DfreeStack(ds);
    free(ds);

    // Testes com queue dinâmica
    DQueue dq = (DQueue)malloc(sizeof(struct dinQueue));
    DinitQueue(dq);
    Denqueue(dq, 70);
    Denqueue(dq, 80);
    Ddequeue(dq, &x);
    printf("Elemento retirado da queue dinâmica: %d\n", x);
    DfreeQueue(dq);
    free(dq);

    return 0;
}