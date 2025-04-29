#include "billing.h"
#include "customer.h"
#include "plan.h"
#include <stdio.h>
#include <string.h>

void Calculate_Bill()
{
    char name[100];
    printf("Enter customer name for bill calculation: ");
    scanf("%s", name);

    for (int i = 0; i < customer_count; i++)
    {
        if (strcmp(customers[i].name, name) == 0)
        {
            int call_duration;
            printf("Enter call duration (in minutes): ");
            scanf("%d", &call_duration);

            if (call_duration < 0)
            {
                printf("Invalid call duration.\n");
                return;
            }

            customers[i].call_duration += call_duration;
            int free_minutes = customers[i].selected_plan.free_minutes;
            float rate = customers[i].selected_plan.rate_per_minute;

            if (free_minutes == -1 || customers[i].call_duration <= free_minutes)
            {
                printf("Free minutes covered the call duration. No extra charges.\n");
                customers[i].bill_amount = 0.0;
            }
            else
            {
                int chargeable_minutes = customers[i].call_duration - free_minutes;
                customers[i].bill_amount += chargeable_minutes * rate;
            }

            printf("Bill updated for %s. Total Amount: $%.2f\n", name, customers[i].bill_amount);
            return;
        }
    }
    printf("Customer not found.\n");
}

void Generate_Bill()
{
    if (customer_count == 0)
    {
        printf("No customers to generate bills for.\n");
        return;
    }

    printf("\n--- Generating Bills for All Customers ---\n");
    for (int i = 0; i < customer_count; i++)
    {
        struct Plan plan = customers[i].selected_plan;
        int free_minutes = plan.free_minutes;
        float rate = plan.rate_per_minute;

        if (free_minutes == -1 || customers[i].call_duration <= free_minutes)
        {
            customers[i].bill_amount = 0.0;
        }
        else
        {
            int chargeable_minutes = customers[i].call_duration - free_minutes;
            customers[i].bill_amount = chargeable_minutes * rate;
        }

        printf("Customer: %s\n", customers[i].name);
        printf("  Phone: %s\n", customers[i].phone);
        printf("  Plan: %s\n", plan.name);
        printf("  Call Duration: %d minutes\n", customers[i].call_duration);
        printf("  Total Bill Amount: $%.2f\n", customers[i].bill_amount);
        printf("-----------------------------\n");
    }
}