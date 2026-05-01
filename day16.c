#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at end
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Reverse the doubly linked list
Node* reverseDLL(Node* head) {
    Node* current = head;
    Node* temp = NULL;

    while (current != NULL) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (which is prev after swap)
        current = current->prev;
    }

    // Update head
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free memory
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int t;
    scanf("%d", &t);  // number of test cases

    while (t--) {
        int n;
        scanf("%d", &n);

        Node* head = NULL;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            head = insertEnd(head, x);
        }

        head = reverseDLL(head);

        printList(head);

        freeList(head);
    }

    return 0;
}