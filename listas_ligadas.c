#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista ligada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no início da lista ligada
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Função para inserir um nó no final da lista ligada
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Função para remover um nó com um valor específico
void removeNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    // Se o nó a ser removido é a cabeça
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Procura pelo nó a ser removido
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Se o nó não foi encontrado
    if (temp == NULL) return;

    // Remove o nó
    prev->next = temp->next;
    free(temp);
}

// Função para buscar um nó com um valor específico
Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Função para exibir a lista ligada
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para reverter a lista ligada
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Função para detectar ciclo em uma lista ligada
int detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // Ciclo detectado
        }
    }
    return 0; // Nenhum ciclo
}

// Função para mesclar duas listas ligadas ordenadas
Node* mergeLists(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    }
}

// Função principal para testar as operações da lista ligada
int main() {
    Node* head = NULL;

    // Inserindo nós na lista ligada
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);

    printf("Lista após inserções: ");
    displayList(head);

    // Removendo um nó da lista ligada
    removeNode(&head, 2);
    printf("Lista após remoção do nó com valor 2: ");
    displayList(head);

    // Buscando um nó na lista ligada
    Node* foundNode = searchNode(head, 3);
    if (foundNode != NULL) {
        printf("Nó com valor 3 encontrado.\n");
    } else {
        printf("Nó com valor 3 não encontrado.\n");
    }

    // Revertendo a lista ligada
    reverseList(&head);
    printf("Lista após reversão: ");
    displayList(head);

    // Detectando ciclo na lista ligada
    int cycleDetected = detectCycle(head);
    if (cycleDetected) {
        printf("Ciclo detectado na lista.\n");
    } else {
        printf("Nenhum ciclo detectado na lista.\n");
    }

    // Criando uma segunda lista para mesclar
    Node* head2 = NULL;
    insertAtEnd(&head2, 5);
    insertAtEnd(&head2, 6);

    printf("Segunda lista: ");
    displayList(head2);

    // Mesclando as duas listas
    Node* mergedList = mergeLists(head, head2);
    printf("Lista mesclada: ");
    displayList(mergedList);

    return 0;
}
