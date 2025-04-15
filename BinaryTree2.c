#include <stdio.h>
#include <stdlib.h>

// Tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node by following path (recursive helper)
Node* insert(Node* root, int data) {
    if (root == NULL) {
        printf("Created root node %d\n", data);
        return createNode(data);
    }

    Node* current = root;
    char ch;

    while (1) {
        printf("Enter direction to insert %d (l/r): ", data);
        scanf(" %c", &ch);

        if (ch == 'l') {
            if (current->left == NULL) {
                current->left = createNode(data);
                break;
            } else {
                current = current->left;
            }
        } else if (ch == 'r') {
            if (current->right == NULL) {
                current->right = createNode(data);
                break;
            } else {
                current = current->right;
            }
        } else {
            printf("Invalid input. Use 'l' or 'r'.\n");
        }
    }

    return root;
}

// Traversals
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Height of tree (used for level-order)
int height(Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Print one level
void printLevel(Node* root, int level) {
    if (root == NULL) return;
    if (level == 1)
        printf("%d ", root->data);
    else {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Level-order using only recursion
void levelOrder(Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printLevel(root, i);
}

int main() {
    Node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nLevel-order: ");
    levelOrder(root);

    printf("\n");
    return 0;
}