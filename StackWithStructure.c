#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("%d pushed onto the stack\n", value);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to peek\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to display\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    printf("Top element is: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}