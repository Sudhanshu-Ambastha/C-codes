#include "customer.h"
#include "plan.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

void Add_Customer()
{
    if (customer_count >= MAX_CUSTOMERS)
    {
        printf("Customer limit reached. Cannot add more customers.\n");
        return;
    }

    printf("Enter customer name: ");
    scanf("%s", customers[customer_count].name);

    char phone[15];
    do
    {
        printf("Enter phone number (10 digits): ");
        scanf("%s", phone);

        if (!Is_Valid_Phone_Number(phone))
            printf("Invalid phone number. Please enter a valid 10-digit phone number.\n");

    } while (!Is_Valid_Phone_Number(phone));

    strcpy(customers[customer_count].phone, phone);

    Display_Plans();
    int plan_choice;
    printf("Select a plan (1-%d): ", plan_count);
    scanf("%d", &plan_choice);
    if (plan_choice < 1 || plan_choice > plan_count)
    {
        printf("Invalid plan choice. Assigning default plan (Basic).\n");
        customers[customer_count].selected_plan = plans[0];
    }
    else
    {
        customers[customer_count].selected_plan = plans[plan_choice - 1];
    }

    customers[customer_count].call_duration = 0;
    customers[customer_count].bill_amount = 0.0;
    customer_count++;
    printf("Customer added successfully.\n");
    // Database saving will be handled in main or a dedicated function
}

void Remove_Customer()
{
    char name[100];
    printf("Enter the name of the customer to remove: ");
    scanf("%s", name);

    for (int i = 0; i < customer_count; i++)
    {
        if (strcmp(customers[i].name, name) == 0)
        {
            for (int j = i; j < customer_count - 1; j++)
            {
                customers[j] = customers[j + 1];
            }
            customer_count--;
            printf("Customer removed successfully.\n");
            // Database saving will be handled in main or a dedicated function
            return;
        }
    }
    printf("Customer not found.\n");
}

void Display_Customers()
{
    if (customer_count == 0)
    {
        printf("No customers to display.\n");
        return;
    }

    printf("\n--- Customer Details ---\n");
    for (int i = 0; i < customer_count; i++)
    {
        printf("Name: %s\n", customers[i].name);
        printf("Phone: %s\n", customers[i].phone);
        printf("Plan: %s\n", customers[i].selected_plan.name);
        printf("Call Duration: %d minutes\n", customers[i].call_duration);
        printf("Bill Amount: $%.2f\n", customers[i].bill_amount);
        printf("-----------------------------\n");
    }
}

void Search_Customer()
{
    char name[100];
    printf("Enter customer name to search: ");
    scanf("%s", name);

    for (int i = 0; i < customer_count; i++)
    {
        if (strstr(customers[i].name, name))
        {
            printf("Name: %s\n", customers[i].name);
            printf("Phone: %s\n", customers[i].phone);
            printf("Plan: %s\n", customers[i].selected_plan.name);
            printf("Call Duration: %d minutes\n", customers[i].call_duration);
            printf("Bill Amount: $%.2f\n", customers[i].bill_amount);
            printf("-----------------------------\n");
            return;
        }
    }
    printf("Customer not found.\n");
}

void Sort_Customers()
{
    for (int i = 0; i < customer_count - 1; i++)
    {
        for (int j = i + 1; j < customer_count; j++)
        {
            if (strcmp(customers[i].name, customers[j].name) > 0)
            {
                struct Customer temp = customers[i];
                customers[i] = customers[j];
                customers[j] = temp;
            }
        }
    }
    printf("Customers sorted alphabetically.\n");
    // Database saving will be handled in main or a dedicated function
}

void Update_Customer()
{
    char name[100];
    printf("Enter the name of the customer to update: ");
    scanf("%s", name);

    for (int i = 0; i < customer_count; i++)
    {
        if (strcmp(customers[i].name, name) == 0)
        {
            int option;
            printf("\n--- Update Options ---\n");
            printf("1. Update Name\n2. Update Phone\n3. Update Plan\n");
            printf("4. Update Call Duration\n5. Update Bill Amount\n");
            printf("Enter your choice: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                printf("Enter new name: ");
                scanf("%s", customers[i].name);
                printf("Name updated successfully.\n");
                break;
            case 2:
            {
                char phone[15];
                do
                {
                    printf("Enter new phone number (10 digits): ");
                    scanf("%s", phone);

                    if (!Is_Valid_Phone_Number(phone))
                        printf("Invalid phone number. Please enter a valid 10-digit phone number.\n");

                } while (!Is_Valid_Phone_Number(phone));

                strcpy(customers[i].phone, phone);
                printf("Phone number updated successfully.\n");
                break;
            }
            case 3:
                Display_Plans();
                int plan_choice;
                printf("Select a new plan (1-%d): ", plan_count);
                scanf("%d", &plan_choice);
                if (plan_choice < 1 || plan_choice > plan_count)
                {
                    printf("Invalid plan choice. No changes made.\n");
                }
                else
                {
                    customers[i].selected_plan = plans[plan_choice - 1];
                    printf("Plan updated successfully.\n");
                }
                break;
            case 4:
                printf("Enter new call duration (in minutes): ");
                int new_duration;
                scanf("%d", &new_duration);
                if (new_duration < 0)
                {
                    printf("Invalid call duration. No changes made.\n");
                }
                else
                {
                    customers[i].call_duration = new_duration;
                    // Bill might need recalculation here, but let's keep it simple for now.
                    printf("Call duration updated successfully.\n");
                }
                break;
            case 5:
                printf("Enter new bill amount: ");
                float new_bill;
                scanf("%f", &new_bill);
                if (new_bill < 0)
                {
                    printf("Invalid bill amount. No changes made.\n");
                }
                else
                {
                    customers[i].bill_amount = new_bill;
                    printf("Bill amount updated successfully.\n");
                }
                break;
            default:
                printf("Invalid choice. No changes made.\n");
                break;
            }
            // Database saving will be handled in main or a dedicated function
            return;
        }
    }
    printf("Customer not found.\n");
}

void Filter_Customers_By_Plan()
{
    if (customer_count == 0)
    {
        printf("No customers available to filter.\n");
        return;
    }

    Display_Plans();
    int plan_choice;
    printf("Select a plan to filter customers (1-%d): ", plan_count);
    scanf("%d", &plan_choice);

    if (plan_choice < 1 || plan_choice > plan_count)
    {
        printf("Invalid plan choice.\n");
        return;
    }

    struct Plan selected_plan = plans[plan_choice - 1];
    printf("\n--- Customers on Plan: %s ---\n", selected_plan.name);

    int found = 0;
    for (int i = 0; i < customer_count; i++)
    {
        if (strcmp(customers[i].selected_plan.name, selected_plan.name) == 0)
        {
            printf("Name: %s\n", customers[i].name);
            printf("Phone: %s\n", customers[i].phone);
            printf("Call Duration: %d minutes\n", customers[i].call_duration);
            printf("Bill Amount: $%.2f\n", customers[i].bill_amount);
            printf("-----------------------------\n");
            found = 1;
        }
    }

    if (!found)
    {
        printf("No customers found on the %s plan.\n", selected_plan.name);
    }
}