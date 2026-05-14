#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to insert node at tail
struct Node* insertNodeAtTail(struct Node* head, int data) {

    // Create new node
    struct Node* newNode = createNode(data);

    // If linked list is empty
    if (head == NULL) {
        return newNode;
    }

    // Traverse to last node
    struct Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert at tail
    temp->next = newNode;

    return head;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {

    struct Node* head = NULL;

    int n, value;

    // Input number of nodes
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insert elements
    for (int i = 0; i < n; i++) {

        printf("Enter value: ");
        scanf("%d", &value);

        head = insertNodeAtTail(head, value);
    }

    // Print linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}