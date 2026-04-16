#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print in reverse using recursion
void reversePrint(struct Node* head) {
    if (head == NULL)
        return;
    
    reversePrint(head->next);  // go to last node
    printf("%d\n", head->data); // print while returning
}

// Helper function to insert node at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    int t;
    scanf("%d", &t); // number of test cases

    while (t--) {
        int n, x;
        scanf("%d", &n);

        struct Node* head = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            head = insert(head, x);
        }

        reversePrint(head); // print reverse
    }

    return 0;
}