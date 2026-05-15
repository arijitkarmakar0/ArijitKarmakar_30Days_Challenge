#include <stdio.h>
#include <stdlib.h>

/* Node structure definition */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* --- The Function Requested --- */
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    // Since the constraints say max 500 nodes, 
    // a simple array-based queue works perfectly.
    struct Node* queue[500];
    int head = 0; // Pointer to the front of the queue
    int tail = 0; // Pointer to the end of the queue

    // Enqueue the root
    queue[tail++] = root;

    while (head < tail) {
        // Dequeue the current node
        struct Node* current = queue[head++];

        // Print the data followed by a space
        printf("%d ", current->data);

        // Enqueue left child
        if (current->left != NULL) {
            queue[tail++] = current->left;
        }

        // Enqueue right child
        if (current->right != NULL) {
            queue[tail++] = current->right;
        }
    }
}

/* Helper function to create a new node */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Helper function to insert nodes (Binary Search Tree style) */
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    
    /* Recreating the sample tree from your image */
    int nodes[] = {1, 2, 5, 3, 6, 4};
    int n = sizeof(nodes) / sizeof(nodes[0]);
    
    for(int i = 0; i < n; i++) {
        root = insert(root, nodes[i]);
    }

    // Expected Output: 1 2 5 3 6 4 
    levelOrder(root);
    printf("\n");

    return 0;
}