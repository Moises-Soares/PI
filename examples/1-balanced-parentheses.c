#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estrutura de nó da pilha
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;

// Função para criar um novo nó na pilha
StackNode* newNode(char data) {
    StackNode* stackNode = (StackNode*) malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Função para verificar se a pilha está vazia
bool isEmpty(StackNode* root) {
    return !root;
}

// Função para empilhar um elemento
void push(StackNode** root, char data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Função para desempilhar um elemento
char pop(StackNode** root) {
    if (isEmpty(*root))
        return '\0';
    StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Função para verificar se os parênteses estão balanceados
bool areParenthesesBalanced(char* expr) {
    StackNode* stack = NULL;
    int i;

    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(') {
            push(&stack, expr[i]);
        } else if (expr[i] == ')') {
            if (isEmpty(stack)) {
                return false;
            } else {
                pop(&stack);
            }
        }
    }

    return isEmpty(stack);
}

int main() {
    char expr[] = "((()))";

    if (areParenthesesBalanced(expr))
        printf("Os parênteses estão balanceados.\n");
    else
        printf("Os parênteses não estão balanceados.\n");

    return 0;
}
