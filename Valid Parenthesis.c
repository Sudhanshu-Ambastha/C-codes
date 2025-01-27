#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            push(c); 
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty()) {
                return 0; 
            }
            char topChar = pop();
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return 0; 
            }
        }
    }
    return isEmpty(); 
}

int main() {
    char str[100];
    printf("Enter a string with parentheses, square brackets, and curly braces: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("The string is balanced.\n");
    } else {
        printf("The string is not balanced.\n");
    }

    return 0;
}