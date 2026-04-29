#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Find merge point (Optimal Solution)
int findMergeNode(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1->data;
}

// Print list (for debugging)
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head1 = NULL, *head2 = NULL;

    // Create List 1: 1 -> 2 -> 3 -> 4 -> 5
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 3);
    insert(&head1, 4);
    insert(&head1, 5);

    // Create List 2: 9 -> 8
    insert(&head2, 9);
    insert(&head2, 8);

    // Create merge point at node with value 3
    Node* temp1 = head1;
    while (temp1->data != 3)
        temp1 = temp1->next;

    Node* temp2 = head2;
    while (temp2->next != NULL)
        temp2 = temp2->next;

    temp2->next = temp1;  // Merge happens here

    // Print lists
    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    // Find merge point
    int result = findMergeNode(head1, head2);

    printf("Merge Point: %d\n", result);

    return 0;
}