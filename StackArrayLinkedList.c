#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow!\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("Item has been successfully pushed\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return;
    }
    int item = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("%d has been successfully popped\n", item);
}

int peek() {
    if (top != NULL) {
        return top->data;
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int isEmpty() {
    return top == NULL;
}

int size() {
    int count = 0;
    struct Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int item;
    char choice[10];
    while (1) {
        printf("Enter pop, push, peek, isEmpty, size, exit: ");
        scanf("%s", choice);
        if (strcmp(choice, "push") == 0) {
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(item);
        } else if (strcmp(choice, "pop") == 0) {
            pop();
        } else if (strcmp(choice, "peek") == 0) {
            int topItem = peek();
            if (topItem != -1)
                printf("The item at top is: %d\n", topItem);
        } else if (strcmp(choice, "isEmpty") == 0) {
            if (isEmpty()) {
                printf("The stack is empty!\n");
            } else {
                printf("The stack is not empty!\n");
            }
        } else if (strcmp(choice, "size") == 0) {
            printf("The size of the stack is: %d\n", size());
        } else if (strcmp(choice, "exit") == 0) {
            printf("Exiting the program\n");
            return 0;
        } else {
            printf("Enter a correct choice!\n");
        }
    }
    return 0;
}