#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build subtree recursively
struct Node* buildSubtree(struct Node* node) {
    char choice, leftVal, rightVal;

    printf("Does node %c have LEFT child? (y/n): ", node->data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter LEFT child of %c: ", node->data);
        scanf(" %c", &leftVal);
        node->left = createNode(leftVal);
        node->left = buildSubtree(node->left);
    }

    printf("Does node %c have RIGHT child? (y/n): ", node->data);
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        printf("Enter RIGHT child of %c: ", node->data);
        scanf(" %c", &rightVal);
        node->right = createNode(rightVal);
        node->right = buildSubtree(node->right);
    }

    return node;
}

// Build full tree
struct Node* buildTree() {
    char val;
    printf("Enter ROOT node value: ");
    scanf(" %c", &val);
    struct Node* root = createNode(val);
    return buildSubtree(root);
}

// Traversals
void preorderRecursive(struct Node* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void inorderRecursive(struct Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%c ", root->data);
    inorderRecursive(root->right);
}

void postorderRecursive(struct Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%c ", root->data);
}

// Tree height (for level-order)
int height(struct Node* root) {
    if (root == NULL) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    return (hl > hr ? hl : hr) + 1;
}

// Print one level
void printLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1)
        printf("%c ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Level-order traversal
void levelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

// Main
int main() {
    struct Node* root = buildTree();

    printf("\nPreorder: ");
    preorderRecursive(root);

    printf("\nInorder: ");
    inorderRecursive(root);

    printf("\nPostorder: ");
    postorderRecursive(root);

    printf("\nLevel-order: ");
    levelOrder(root);

    printf("\n");
    return 0;
}