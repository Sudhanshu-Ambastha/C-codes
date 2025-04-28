#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int findSmallest(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int getHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node* root) {
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, count, i;

    do {
        printf("\n1. Insert elements\n");
        printf("2. Print preorder traversal\n");
        printf("3. Print inorder traversal\n");
        printf("4. Print postorder traversal\n");
        printf("5. Print level order traversal\n");
        printf("6. Find smallest element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many elements do you want to insert? ");
                scanf("%d", &count);
                for (i = 0; i < count; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Level order traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 6:
                data = findSmallest(root);
                if (data != -1) {
                    printf("Smallest element: %d\n", data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    freeTree(root);
    return 0;
}
