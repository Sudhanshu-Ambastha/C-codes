#include "data_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List Functions
struct ListNode *create_list_node(struct Customer customer)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->data = customer;
    node->next = NULL;
    return node;
}

void display_linked_list(struct ListNode *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct ListNode *current = head;
    while (current != NULL)
    {
        printf("Name: %s, Phone: %s, Plan: %s\n",
               current->data.name, current->data.phone, current->data.selected_plan.name);
        current = current->next;
    }
}

// Binary Tree Functions
struct TreeNode *create_tree_node(struct Customer customer)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = customer;
    node->left = node->right = NULL;
    return node;
}

void insert_tree_node(struct TreeNode **root, struct Customer customer)
{
    if (*root == NULL)
    {
        *root = create_tree_node(customer);
        return;
    }

    // Simple insertion based on name comparison
    if (strcmp(customer.name, (*root)->data.name) < 0)
    {
        insert_tree_node(&(*root)->left, customer);
    }
    else
    {
        insert_tree_node(&(*root)->right, customer);
    }
}

void display_inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        display_inorder(root->left);
        printf("Name: %s, Phone: %s, Plan: %s\n",
               root->data.name, root->data.phone, root->data.selected_plan.name);
        display_inorder(root->right);
    }
}

int is_full_binary_tree(struct TreeNode *root)
{
    if (root == NULL)
        return 1;

    // If a node has only one child, it's not a full binary tree
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL))
    {
        return 0;
    }

    // Recursively check left and right subtrees
    return is_full_binary_tree(root->left) && is_full_binary_tree(root->right);
}

int count_nodes(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int is_complete_binary_tree(struct TreeNode *root, int index, int node_count)
{
    if (root == NULL)
        return 1;

    if (index >= node_count)
        return 0;

    return is_complete_binary_tree(root->left, 2 * index + 1, node_count) &&
           is_complete_binary_tree(root->right, 2 * index + 2, node_count);
}

// Queue Functions
void init_queue(struct Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(struct Queue *q, struct Customer customer)
{
    struct ListNode *new_node = create_list_node(customer);

    if (q->rear == NULL)
    {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

struct Customer dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        struct Customer empty;
        memset(&empty, 0, sizeof(empty));
        return empty;
    }

    struct ListNode *temp = q->front;
    struct Customer data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

int is_queue_empty(struct Queue *q)
{
    return q->front == NULL;
}

void display_queue(struct Queue *q)
{
    if (is_queue_empty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct ListNode *current = q->front;
    while (current != NULL)
    {
        printf("Name: %s, Phone: %s, Plan: %s\n",
               current->data.name, current->data.phone, current->data.selected_plan.name);
        current = current->next;
    }
}