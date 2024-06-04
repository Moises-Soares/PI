#include <stdio.h>
#include <stdlib.h>

// Definição de LInt
typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

// Função para criar um novo LInt
LInt newLInt(int x, LInt xs) {
    LInt r = malloc(sizeof(struct slist));
    if (r != NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

// Definições para Stack
typedef LInt Stack;

void initStack(Stack *s) {
    *s = NULL;
}

int SisEmpty(Stack s) {
    return s == NULL;
}

int push(Stack *s, int x) {
    LInt new = newLInt(x, *s);
    if (new == NULL) return 0;
    *s = new;
    return 1;
}

int pop(Stack *s, int *x) {
    if (*s == NULL) return 0;
    LInt temp = *s;
    *x = temp->valor;
    *s = temp->prox;
    free(temp);
    return 1;
}

int top(Stack s, int *x) {
    if (s == NULL) return 0;
    *x = s->valor;
    return 1;
}

// Definições para Queue
typedef struct {
    LInt inicio, fim;
} Queue;

void initQueue(Queue *q) {
    q->inicio = q->fim = NULL;
}

int QisEmpty(Queue q) {
    return q.inicio == NULL;
}

int enqueue(Queue *q, int x) {
    LInt new = newLInt(x, NULL);
    if (new == NULL) return 0;
    if (q->fim != NULL) {
        q->fim->prox = new;
    } else {
        q->inicio = new;
    }
    q->fim = new;
    return 1;
}

int dequeue(Queue *q, int *x) {
    if (q->inicio == NULL) return 0;
    LInt temp = q->inicio;
    *x = temp->valor;
    q->inicio = temp->prox;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    free(temp);
    return 1;
}

int front(Queue q, int *x) {
    if (q.inicio == NULL) return 0;
    *x = q.inicio->valor;
    return 1;
}

// Definições para Deque
typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

void initDeque(Deque *q) {
    q->back = q->front = NULL;
}

int DisEmpty(Deque q) {
    return q.front == NULL;
}

int pushBack(Deque *q, int x) {
    DList new = malloc(sizeof(struct dlist));
    if (new == NULL) return 0;
    new->valor = x;
    new->prox = NULL;
    new->ant = q->back;
    if (q->back != NULL) {
        q->back->prox = new;
    } else {
        q->front = new;
    }
    q->back = new;
    return 1;
}

int pushFront(Deque *q, int x) {
    DList new = malloc(sizeof(struct dlist));
    if (new == NULL) return 0;
    new->valor = x;
    new->ant = NULL;
    new->prox = q->front;
    if (q->front != NULL) {
        q->front->ant = new;
    } else {
        q->back = new;
    }
    q->front = new;
    return 1;
}

int popBack(Deque *q, int *x) {
    if (q->back == NULL) return 0;
    DList temp = q->back;
    *x = temp->valor;
    q->back = temp->ant;
    if (q->back != NULL) {
        q->back->prox = NULL;
    } else {
        q->front = NULL;
    }
    free(temp);
    return 1;
}

int popFront(Deque *q, int *x) {
    if (q->front == NULL) return 0;
    DList temp = q->front;
    *x = temp->valor;
    q->front = temp->prox;
    if (q->front != NULL) {
        q->front->ant = NULL;
    } else {
        q->back = NULL;
    }
    free(temp);
    return 1;
}

int popMax(Deque *q, int *x) {
    if (q->front == NULL) return 0;
    DList max = q->front, temp = q->front;
    while (temp != NULL) {
        if (temp->valor > max->valor) {
            max = temp;
        }
        temp = temp->prox;
    }
    *x = max->valor;
    if (max->ant != NULL) {
        max->ant->prox = max->prox;
    } else {
        q->front = max->prox;
    }
    if (max->prox != NULL) {
        max->prox->ant = max->ant;
    } else {
        q->back = max->ant;
    }
    free(max);
    return 1;
}

int back(Deque q, int *x) {
    if (q.back == NULL) return 0;
    *x = q.back->valor;
    return 1;
}

int front(Deque q, int *x) {
    if (q.front == NULL) return 0;
    *x = q.front->valor;
    return 1;
}

/*
Sugestões de exercícios:

1. Implemente uma função que inverta uma stack. A função deve ter a seguinte assinatura:
   void reverseStack(Stack *s);

2. Implemente uma função que mescle duas queues em uma nova queue, intercalando os elementos de cada uma. A função deve ter a seguinte assinatura:
   Queue mergeQueues(Queue q1, Queue q2);
*/

int main() {
    // Aqui você pode testar as funções implementadas
    return 0;
}