#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }
    return count;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value, key;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Linked List: ");
    display(head);

    printf("Enter the element to count: ");
    scanf("%d", &key);

    int count = countOccurrences(head, key);
    printf("Element %d appears %d times in the linked list.\n", key, count);

    return 0;
}