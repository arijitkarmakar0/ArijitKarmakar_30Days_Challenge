#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of Huffman Tree Node
typedef struct node {
    char data;
    struct node *left;
    struct node *right;
} node;

// Create new node
node* newNode(char data) {

    node* temp = (node*)malloc(sizeof(node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Huffman Decoding Function
void decode_huff(node *root, char *s) {

    node *curr = root;

    while (*s) {

        // Move in tree
        if (*s == '0')
            curr = curr->left;
        else
            curr = curr->right;

        // If leaf node
        if (curr->left == NULL && curr->right == NULL) {

            printf("%c", curr->data);

            // Restart from root
            curr = root;
        }

        s++;
    }
}

int main() {

    /*
            Example Huffman Tree

                    (*)
                   /   \
                 B      (*)
                       /   \
                      C     A

            Codes:
            B -> 0
            C -> 10
            A -> 11
    */

    // Create Huffman Tree
    node *root = newNode('*');

    root->left = newNode('B');

    root->right = newNode('*');
    root->right->left = newNode('C');
    root->right->right = newNode('A');

    // Encoded string
    char encoded[] = "1101011";

    printf("Encoded String : %s\n", encoded);

    printf("Decoded String : ");

    decode_huff(root, encoded);

    return 0;
}