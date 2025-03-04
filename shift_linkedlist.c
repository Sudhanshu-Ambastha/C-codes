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

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int length(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void leftShift(struct Node** head, int k) {
    if (*head == NULL || k == 0)
        return;

    int len = length(*head);
    k = k % len;
    if (k == 0)
        return;

    struct Node* temp = *head;
    struct Node* newHead = NULL;
    struct Node* prev = NULL;

    for (int i = 0; i < k; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    newHead = temp;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head;
    *head = newHead;
}

void rightShift(struct Node** head, int k) {
    if (*head == NULL || k == 0)
        return;

    int len = length(*head);
    k = k % len;
    if (k == 0)
        return;

    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    for (int i = 0; i < len - k; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    struct Node* newHead = temp;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = *head;
    *head = newHead;
}

int main() {
    struct Node* head = NULL;
    int n, value, k, choice;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Original Linked List: ");
    display(head);

    printf("Enter the number of positions to shift: ");
    scanf("%d", &k);

    printf("Enter 1 for Left Shift or 2 for Right Shift: ");
    scanf("%d", &choice);

    if (choice == 1) {
        leftShift(&head, k);
        printf("Linked List after Left Shift: ");
    } else if (choice == 2) {
        rightShift(&head, k);
        printf("Linked List after Right Shift: ");
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    display(head);
    return 0;
}