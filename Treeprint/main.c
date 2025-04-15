#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TREEPRINT.h"

// Define a simple binary tree node with integer data
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Utility to create a new node
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Adapter functions for treeprint
TreeNode getLeft(TreeNode node) {
    return ((Node*)node)->left;
}

TreeNode getRight(TreeNode node) {
    return ((Node*)node)->right;
}

const char* getData(TreeNode node) {
    static char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", ((Node*)node)->value);
    return buffer;
}

int main() {
    // Create a sample binary tree:
    //
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Print the tree
    printf("Visualized Binary Tree:\n");
    printTree(root, getLeft, getRight, getData);

    return 0;
}