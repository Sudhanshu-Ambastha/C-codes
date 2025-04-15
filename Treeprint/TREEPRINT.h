#ifndef TREEPRINT_H
#define TREEPRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Generic pointer to any node type
typedef void* TreeNode;

// Function pointer types for accessing a node's left, right, and data
typedef TreeNode (*GetLeftFunc)(TreeNode);
typedef TreeNode (*GetRightFunc)(TreeNode);
typedef const char* (*GetDataFunc)(TreeNode);

// Simple queue structure for level-order traversal
typedef struct Queue {
    TreeNode *array;
    int front, rear, size;
} Queue;

// Queue operations
Queue* createQueue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->array = (TreeNode*)malloc(sizeof(TreeNode) * size);
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, TreeNode node) {
    if (q->rear < q->size)
        q->array[q->rear++] = node;
}

TreeNode dequeue(Queue* q) {
    if (!isEmpty(q))
        return q->array[q->front++];
    return NULL;
}

// Get tree height
int getHeight(TreeNode root, GetLeftFunc getLeft, GetRightFunc getRight) {
    if (!root) return 0;
    int lh = getHeight(getLeft(root), getLeft, getRight);
    int rh = getHeight(getRight(root), getLeft, getRight);
    return (lh > rh ? lh : rh) + 1;
}

// Print a number of spaces
void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

// Main tree visualization function
void printTree(TreeNode root, GetLeftFunc getLeft, GetRightFunc getRight, GetDataFunc getData) {
    if (!root) return;

    int height = getHeight(root, getLeft, getRight);
    int maxNodes = (1 << height) - 1;
    int maxWidth = maxNodes * 2;

    Queue *q = createQueue(2048);
    enqueue(q, root);

    for (int level = 1; level <= height; level++) {
        int nodes = 1 << (level - 1);
        int spaceBetween = maxWidth / nodes;
        int leadingSpaces = spaceBetween / 2;

        printSpaces(leadingSpaces - 1);
        for (int i = 0; i < nodes; i++) {
            TreeNode curr = dequeue(q);
            if (curr) {
                printf("%s", getData(curr));
                enqueue(q, getLeft(curr));
                enqueue(q, getRight(curr));
            } else {
                printf(" ");
                enqueue(q, NULL);
                enqueue(q, NULL);
            }
            printSpaces(spaceBetween - 1);
        }
        printf("\n");

        if (level < height) {
            printSpaces(leadingSpaces - 2);
            for (int i = 0; i < nodes; i++) {
                TreeNode left = q->array[q->front + i * 2];
                TreeNode right = q->array[q->front + i * 2 + 1];
                if (left || right) {
                    printf("%s", left ? "/" : " ");
                    printf(" ");
                    printf("%s", right ? "\\" : " ");
                } else {
                    printf("   ");
                }
                printSpaces(spaceBetween - 3);
            }
            printf("\n");
        }
    }

    free(q->array);
    free(q);
}

#endif // TREEPRINT_H