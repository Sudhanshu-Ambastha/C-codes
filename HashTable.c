#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *key;
    int value;
    struct Node *next;
};

struct HashTable {
    int size;
    struct Node **table;
};

struct Node *createNode(char *key, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int hash(char *key, int tableSize) {
    int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + key[i]) % tableSize;
    }
    return hashValue;
}

struct HashTable *initHashTable(int size) {
    struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));
    if (!ht) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    ht->size = size;
    ht->table = (struct Node **)calloc(size, sizeof(struct Node *));
    if (!ht->table) {
        perror("Memory allocation failed");
        free(ht);
        exit(EXIT_FAILURE);
    }
    return ht;
}

void insert(struct HashTable *ht, char *key, int value) {
    int index = hash(key, ht->size);
    struct Node *newNode = createNode(key, value);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int search(struct HashTable *ht, char *key) {
    int index = hash(key, ht->size);
    struct Node *current = ht->table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(struct HashTable *ht, char *key) {
    int index = hash(key, ht->size);
    struct Node *current = ht->table[index];
    struct Node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void freeHashTable(struct HashTable *ht) {
    if (ht == NULL) {
        return;
    }
    for (int i = 0; i < ht->size; i++) {
        struct Node *current = ht->table[i];
        while (current != NULL) {
            struct Node *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

int main() {
    int size;
    printf("Enter the initial size of the hash table: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid size. Exiting.\n");
        return 1;
    }
    struct HashTable *myHashTable = initHashTable(size);
    char operation[10];
    char key[50];
    int value;

    while (1) {
        printf("\nEnter operation (insert/search/delete/exit): ");
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(myHashTable, key, value);
        } else if (strcmp(operation, "search") == 0) {
            printf("Enter key to search: ");
            scanf("%s", key);
            int result = search(myHashTable, key);
            if (result != -1) {
                printf("Value for '%s': %d\n", key, result);
            } else {
                printf("Key '%s' not found.\n", key);
            }
        } else if (strcmp(operation, "delete") == 0) {
            printf("Enter key to delete: ");
            scanf("%s", key);
            delete(myHashTable, key);
            printf("Key '%s' deleted (if found).\n", key);
        } else if (strcmp(operation, "exit") == 0) {
            break;
        } else {
            printf("Invalid operation.\n");
        }
    }

    freeHashTable(myHashTable);
    return 0;
}
