#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "customer.h"

// Node for linked list
struct ListNode
{
    struct Customer data;
    struct ListNode *next;
};

// Node for binary tree
struct TreeNode
{
    struct Customer data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure
struct Queue
{
    struct ListNode *front;
    struct ListNode *rear;
};

struct ListNode *create_list_node(struct Customer customer);
void display_linked_list(struct ListNode *head);

struct TreeNode *create_tree_node(struct Customer customer);
void insert_tree_node(struct TreeNode **root, struct Customer customer);
void display_inorder(struct TreeNode *root);
int is_full_binary_tree(struct TreeNode *root);
int is_complete_binary_tree(struct TreeNode *root, int index, int node_count);
int count_nodes(struct TreeNode *root);

void init_queue(struct Queue *q);
void enqueue(struct Queue *q, struct Customer customer);
struct Customer dequeue(struct Queue *q);
int is_queue_empty(struct Queue *q);
void display_queue(struct Queue *q);

#endif