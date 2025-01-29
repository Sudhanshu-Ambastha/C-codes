#include <stdio.h>

#define MAXSIZE 5

int queue[MAXSIZE], front = -1, rear = -1;

void insert(int item) {
    if (rear == MAXSIZE - 1) {
        printf("\nOverflow");
    } else {
        rear = rear + 1;
        queue[rear] = item;
        if (front == -1) {
            front = rear;
        }
        printf("\nInserted: %d", item);
    }
}

int delete() {
    int item = 0;
    if (front == -1) {
        printf("\nUnderflow");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
    }
    return item;
}

void traverse() {
    if (front == -1) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice1, choice2, item;
    do {
        printf("\n\nEnter choice:\n1 - Insert\n2 - Delete\n3 - Traverse\n4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1) {
            case 1:
                printf("\nInput item: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                item = delete();
                if (item != -1)
                    printf("\nDeleted item = %d", item);
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("\nExiting program...");
                return 0;

            default:
                printf("\nInvalid choice.");
        }

        printf("\nInput 1 to continue, 0 to exit: ");
        scanf("%d", &choice2);
    } while (choice2 == 1);

    return 0;
}