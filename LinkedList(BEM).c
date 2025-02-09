//Creating and Traversing and insertion into a linked list (at beg, at end and at middle)
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
int data;
struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

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
void traverseList() {
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

// Function to insert at the beginning
void insertAtBeginning(int data) {
struct Node* newNode = createNode(data);
newNode->next = head->next; // Link new node to the first node
head->next = newNode; // Update head's next pointer
printf("Inserted %d at the beginning.\n", data);
}

// Function to insert at the end
void insertAtEnd(int data) {
struct Node* temp = head;
while (temp->next != NULL) {
temp = temp->next; // Traverse to the end of the list
}
struct Node* newNode = createNode(data);
temp->next = newNode; // Link the new node at the end
printf("Inserted %d at the end.\n", data);
}

// Function to insert at a specific position (middle)
void insertAtMiddle(int position, int data) {
struct Node* temp = head;

int count = 0;

// Traverse to the position before the target
while (temp != NULL && count < position - 1) {
temp = temp->next;
count++;
}

// Check if position is valid
if (temp == NULL) {
printf("Invalid position.\n");
return;
}

struct Node* newNode = createNode(data);
newNode->next = temp->next; // Link the new node to the next node
temp->next = newNode; // Link the previous node to the new node
printf("Inserted %d at position %d.\n", data, position);
}

int main() {
// Create the head node
head = (struct Node*)malloc(sizeof(struct Node));
if (!head) {
printf("Memory allocation failed.\n");
return 1;
}
head->data = 0; // Head node initialized with 0 (or NULL for data)
head->next = NULL;

printf("Head node created with data = %d\n", head->data);

// Create initial nodes
int n, data;
printf("How many nodes do you want to create initially? ");
scanf("%d", &n);

struct Node* temp = head;
for (int i = 0; i < n; i++) {
printf("Enter data for node %d: ", i + 1);
scanf("%d", &data);

struct Node* newNode = createNode(data);
temp->next = newNode; // Link the new node to the list
temp = newNode; // Move temp to the new node
}

// Traverse the initial list
traverseList();

// Insert at the beginning
printf("\nInserting at the beginning...\n");
printf("Enter data to insert at beginning: ");
scanf("%d", &data);
insertAtBeginning(data);
traverseList();

// Insert at the end
printf("\nInserting at the end...\n");
printf("Enter data to insert at end: ");
scanf("%d", &data);
insertAtEnd(data);

traverseList();

// Insert in the middle
printf("\nInserting in the middle...\n");
int position;
printf("Enter position to insert: ");
scanf("%d", &position);
printf("Enter data to insert at position %d: ", position);
scanf("%d", &data);
insertAtMiddle(position, data);
traverseList();

return 0;
}
