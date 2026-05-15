#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of the Singly Linked List Node
typedef struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

// Helper function to create a new node
SinglyLinkedListNode* create_node(int data) {
    SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
 * Complete the 'has_cycle' function below.
 * Returns 1 if there is a cycle, 0 otherwise.
 */
bool has_cycle(SinglyLinkedListNode* head) {
    if (head == NULL) {
        return false;
    }

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    // Fast pointer moves twice as quickly as the slow pointer
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move 1 step
        fast = fast->next->next;    // Move 2 steps

        // If they meet, a cycle exists
        if (slow == fast) {
            return true;
        }
    }

    // If fast reaches the end, no cycle exists
    return false;
}

int main() {
    // --- Scenario 1: No Cycle (1 -> 2 -> 3 -> NULL) ---
    SinglyLinkedListNode* head1 = create_node(1);
    head1->next = create_node(2);
    head1->next->next = create_node(3);

    printf("List 1 (No Cycle) result: %d\n", has_cycle(head1)); // Expected: 0

    // --- Scenario 2: With Cycle (1 -> 2 -> 3 -> back to 2) ---
    SinglyLinkedListNode* head2 = create_node(1);
    SinglyLinkedListNode* node2 = create_node(2);
    SinglyLinkedListNode* node3 = create_node(3);

    head2->next = node2;
    node2->next = node3;
    node3->next = node2; // Creating the cycle here

    printf("List 2 (With Cycle) result: %d\n", has_cycle(head2)); // Expected: 1

    // Note: In a real app, you'd need to be careful freeing memory 
    // with cycles to avoid infinite loops!
    
    return 0;
}