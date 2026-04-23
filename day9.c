#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure for the Doubly Linked List Node
typedef struct DoublyLinkedListNode {
    int data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
} DoublyLinkedListNode;

// Helper function to create a new node
DoublyLinkedListNode* create_doubly_linked_list_node(int node_data) {
    DoublyLinkedListNode* node = malloc(sizeof(DoublyLinkedListNode));
    node->data = node_data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/*
 * The Algorithm:
 * 1. Create the new node.
 * 2. Handle empty list or head insertion first.
 * 3. Otherwise, find the correct spot and bridge the 4 pointers.
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = create_doubly_linked_list_node(data);

    // Scenario 1: Empty List
    if (llist == NULL) {
        return newNode;
    }

    // Scenario 2: Insert at the Head
    if (data <= llist->data) {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }

    // Scenario 3: Insert in Middle or Tail
    DoublyLinkedListNode* current = llist;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Link newNode between current and current->next
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;

    return llist;
}

// Helper to print the list to the console
void print_list(DoublyLinkedListNode* node) {
    while (node) {
        printf("%d", node->data);
        node = node->next;
        if (node) printf(" <-> ");
    }
    printf(" -> NULL\n");
}

int main() {
    // Manually setting up a test case
    // Existing list: 1 <-> 3 <-> 4 <-> 10
    DoublyLinkedListNode* head = create_doubly_linked_list_node(1);
    DoublyLinkedListNode* n2 = create_doubly_linked_list_node(3);
    DoublyLinkedListNode* n3 = create_doubly_linked_list_node(4);
    DoublyLinkedListNode* n4 = create_doubly_linked_list_node(10);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    printf("Original List: ");
    print_list(head);

    int data_to_insert = 5;
    printf("Inserting %d...\n", data_to_insert);
    
    head = sortedInsert(head, data_to_insert);

    printf("Updated List:  ");
    print_list(head);

    return 0;
}