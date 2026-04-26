#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Queue structure for BFS
struct QNode {
    struct node* treeNode;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

// Create Queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct node* root, int hd) {
    q->rear++;
    q->arr[q->rear].treeNode = root;
    q->arr[q->rear].hd = hd;
}

// Dequeue
struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Insert into BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Top View Function
void topView(struct node* root) {

    if (root == NULL) return;

    int map[2000];
    int visited[2000] = {0};
    int offset = 1000;

    int min_hd = 0, max_hd = 0;

    struct Queue* q = createQueue(1000);

    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);

        struct node* curr = temp.treeNode;
        int hd = temp.hd;

        if (visited[hd + offset] == 0) {
            map[hd + offset] = curr->data;
            visited[hd + offset] = 1;

            if (hd < min_hd) min_hd = hd;
            if (hd > max_hd) max_hd = hd;
        }

        if (curr->left != NULL)
            enqueue(q, curr->left, hd - 1);

        if (curr->right != NULL)
            enqueue(q, curr->right, hd + 1);
    }

    for (int i = min_hd; i <= max_hd; i++) {
        if (visited[i + offset])
            printf("%d ", map[i + offset]);
    }
}

// Driver Code
int main() {

    struct node* root = NULL;

    int n, x;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Top View: ");
    topView(root);

    return 0;
}