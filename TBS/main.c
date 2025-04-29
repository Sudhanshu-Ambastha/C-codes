#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "customer.h"
#include "plan.h"
#include "billing.h"
#include "database.h"
#include "data_structures.h"

int main()
{
    Load_From_DB(); // Load data from file at startup

    int option;
    while (1)
    {
        printf("\n--- Telecom Billing System ---\n");
        printf("1. Add Customer\n");
        printf("2. Remove Customer\n");
        printf("3. Display Customers\n");
        printf("4. Calculate Bill\n");
        printf("5. Search Customer\n");
        printf("6. Sort Customers\n");
        printf("7. Display Plans\n");
        printf("8. Add New Plan\n");
        printf("9. Generate Bills\n");
        printf("10. Update Customer\n");
        printf("11. Filter Customers by Plan\n");
        printf("12. Display Data Structures\n"); // New option for data structures
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Add_Customer();
            Save_To_DB();
            break;
        case 2:
            Remove_Customer();
            Save_To_DB();
            break;
        case 3:
            Display_Customers();
            break;
        case 4:
            Calculate_Bill();
            Save_To_DB();
            break;
        case 5:
            Search_Customer();
            break;
        case 6:
            Sort_Customers();
            Save_To_DB();
            break;
        case 7:
            Display_Plans();
            break;
        case 8:
            Add_New_Plan();
            Save_To_DB();
            break;
        case 9:
            Generate_Bill();
            Save_To_DB();
            break;
        case 10:
            Update_Customer();
            Save_To_DB();
            break;
        case 11:
            Filter_Customers_By_Plan();
            break;
        case 12:
        {
            // Display data structures
            printf("\n--- Data Structures ---\n");

            // Create and display linked list
            struct ListNode *list_head = NULL;
            struct ListNode *current = NULL;
            for (int i = 0; i < customer_count; i++)
            {
                struct ListNode *new_node = create_list_node(customers[i]);
                if (list_head == NULL)
                {
                    list_head = new_node;
                    current = new_node;
                }
                else
                {
                    current->next = new_node;
                    current = current->next;
                }
            }
            printf("\nLinked List of Customers:\n");
            display_linked_list(list_head);

            // Create and display binary tree
            struct TreeNode *tree_root = NULL;
            for (int i = 0; i < customer_count; i++)
            {
                insert_tree_node(&tree_root, customers[i]);
            }
            printf("\nBinary Tree of Customers (Inorder):\n");
            display_inorder(tree_root);

            // Check if the tree is full or complete
            if (tree_root != NULL)
            {
                printf("\nBinary Tree Properties:\n");
                if (is_full_binary_tree(tree_root))
                {
                    printf("- This is a Full Binary Tree\n");
                }
                else
                {
                    printf("- This is NOT a Full Binary Tree\n");
                }

                int node_count = count_nodes(tree_root);
                if (is_complete_binary_tree(tree_root, 0, node_count))
                {
                    printf("- This is a Complete Binary Tree\n");
                }
                else
                {
                    printf("- This is NOT a Complete Binary Tree\n");
                }
            }

            // Create and display queue
            struct Queue customer_queue;
            init_queue(&customer_queue);
            for (int i = 0; i < customer_count; i++)
            {
                enqueue(&customer_queue, customers[i]);
            }
            printf("\nQueue of Customers:\n");
            display_queue(&customer_queue);

            break;
        }
        case 0:
            Save_To_DB(); // Save data to file before exiting
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}