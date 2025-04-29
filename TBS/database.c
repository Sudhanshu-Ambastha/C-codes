#include "database.h"
#include "customer.h"
#include "plan.h"
#include <stdio.h>
#include <string.h>

#define DB_FILE "telecom_db.txt"

void Save_To_DB()
{
    FILE *file = fopen(DB_FILE, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // Save plans
    fprintf(file, "Plans\n");
    for (int i = 0; i < plan_count; i++)
    {
        fprintf(file, "%s %.2f %d %d\n",
                plans[i].name, plans[i].rate_per_minute,
                plans[i].free_minutes, plans[i].data_limit);
    }

    // Save customers
    fprintf(file, "Customers\n");
    for (int i = 0; i < customer_count; i++)
    {
        fprintf(file, "%s %s %d %.2f %s %.2f %d %d\n",
                customers[i].name, customers[i].phone,
                customers[i].call_duration, customers[i].bill_amount,
                customers[i].selected_plan.name, customers[i].selected_plan.rate_per_minute,
                customers[i].selected_plan.free_minutes, customers[i].selected_plan.data_limit);
    }

    fclose(file);
}

void Load_From_DB()
{
    FILE *file = fopen(DB_FILE, "r");
    if (file == NULL)
    {
        printf("No existing database found. Starting with empty records.\n");
        return;
    }

    char line[256];
    int section = 0; // 0=none, 1=plans, 2=customers

    while (fgets(line, sizeof(line), file))
    {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, "Plans") == 0)
        {
            section = 1;
            plan_count = 0;
            continue;
        }
        else if (strcmp(line, "Customers") == 0)
        {
            section = 2;
            customer_count = 0;
            continue;
        }

        if (section == 1)
        {
            // Read plan data
            sscanf(line, "%s %f %d %d",
                   plans[plan_count].name, &plans[plan_count].rate_per_minute,
                   &plans[plan_count].free_minutes, &plans[plan_count].data_limit);
            plan_count++;
        }
        else if (section == 2)
        {
            // Read customer data
            struct Customer cust;
            struct Plan plan;

            sscanf(line, "%s %s %d %f %s %f %d %d",
                   cust.name, cust.phone, &cust.call_duration, &cust.bill_amount,
                   plan.name, &plan.rate_per_minute, &plan.free_minutes, &plan.data_limit);

            // Find the matching plan
            int plan_found = 0;
            for (int i = 0; i < plan_count; i++)
            {
                if (strcmp(plan.name, plans[i].name) == 0)
                {
                    cust.selected_plan = plans[i];
                    plan_found = 1;
                    break;
                }
            }

            if (!plan_found)
            {
                // If plan not found, assign the first plan as default
                cust.selected_plan = plans[0];
            }

            customers[customer_count++] = cust;
        }
    }

    fclose(file);
}