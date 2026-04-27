#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node *lca(struct node *root, int v1, int v2) {

    if (v1 > v2) {
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }

    while (root != NULL) {

        if (v2 < root->data) {
            root = root->left;
        }
        else if (v1 > root->data) {
            root = root->right;
        }
        else {
            return root;
        }
    }

    return NULL;
}

int main() {
    struct node* root = NULL;
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);

    struct node *ans = lca(root, v1, v2);

    if (ans != NULL) {
        printf("%d\n", ans->data);
    }

    return 0;
}