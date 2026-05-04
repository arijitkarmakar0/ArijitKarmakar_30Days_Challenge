#include <stdio.h>
#include <stdlib.h>

// Inorder traversal
void inorder(int node, int** tree, int* result, int* idx) {
    if (node == -1) return;

    inorder(tree[node][0], tree, result, idx);
    result[(*idx)++] = node;
    inorder(tree[node][1], tree, result, idx);
}

// Swap nodes at multiples of k
void swapAtK(int node, int depth, int k, int** tree) {
    if (node == -1) return;

    if (depth % k == 0) {
        int temp = tree[node][0];
        tree[node][0] = tree[node][1];
        tree[node][1] = temp;
    }

    swapAtK(tree[node][0], depth + 1, k, tree);
    swapAtK(tree[node][1], depth + 1, k, tree);
}

// Main function required by problem
int** swapNodes(int n, int** indexes, int queries_count, int* queries, int* result_rows, int* result_columns) {

    // Create tree (1-based indexing)
    int** tree = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        tree[i] = (int*)malloc(2 * sizeof(int));
        tree[i][0] = indexes[i - 1][0];
        tree[i][1] = indexes[i - 1][1];
    }

    int** result = (int**)malloc(queries_count * sizeof(int*));

    for (int q = 0; q < queries_count; q++) {

        int k = queries[q];

        // Perform swap
        swapAtK(1, 1, k, tree);

        // Inorder traversal
        result[q] = (int*)malloc(n * sizeof(int));
        int idx = 0;
        inorder(1, tree, result[q], &idx);
    }

    *result_rows = queries_count;
    *result_columns = n;

    return result;
}

// ------------------ DRIVER CODE ------------------

int main() {
    int n;
    scanf("%d", &n);

    int** indexes = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        indexes[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &indexes[i][0], &indexes[i][1]);
    }

    int t;
    scanf("%d", &t);

    int* queries = (int*)malloc(t * sizeof(int));
    for (int i = 0; i < t; i++) {
        scanf("%d", &queries[i]);
    }

    int result_rows, result_columns;
    int** result = swapNodes(n, indexes, t, queries, &result_rows, &result_columns);

    // Print output
    for (int i = 0; i < result_rows; i++) {
        for (int j = 0; j < result_columns; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}