//Creating and Traversing a linked list
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
int data;
struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation failed.\n");
exit(1);
}
newNode->data = data;
newNode->next = NULL;
return newNode;
}

// Function to traverse the linked list
void traverseList(struct Node* head) {
if (head == NULL || head->next == NULL) {
printf("The list is empty.\n");
return;
}
struct Node* temp = head->next; // Skip the head node for traversal
printf("Linked List: ");
while (temp != NULL) {

printf("%d -> ", temp->data);
temp = temp->next;
}
printf("NULL\n");
}

int main() {
struct Node* head = (struct Node*)malloc(sizeof(struct Node));
if (!head) {
printf("Memory allocation failed.\n");
return 1;
}
head->data = 0; // Head node initialized with 0 (or can set to NULL for data)
head->next = NULL;

printf("Head node created with data = %d\n", head->data);

int n, data;
printf("How many nodes do you want to create? ");
scanf("%d", &n);

struct Node* temp = head;

for (int i = 0; i < n; i++) {
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);

struct Node* newNode = createNode(data);
temp->next = newNode; // Link the new node to the current list
temp = newNode; // Move temp to the newly created node
}

// Traverse the linked list
traverseList(head);

return 0;
}
