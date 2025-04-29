#include "plan.h"
#include <stdio.h>
#include <string.h>

struct Plan plans[MAX_PLANS] = {
    {"Basic", 0.50, 50, 500},
    {"Standard", 0.30, 200, 2000},
    {"Premium", 0.20, 500, 10000},
    {"Unlimited", 1.00, -1, -1}};

int plan_count = 4;

void Display_Plans()
{
    printf("\n--- Available Tariff Plans ---\n");
    for (int i = 0; i < plan_count; i++)
    {
        char free_minutes_display[20];
        char data_limit_display[20];

        if (plans[i].free_minutes == -1)
            strcpy(free_minutes_display, "Unlimited");
        else
            sprintf(free_minutes_display, "%d", plans[i].free_minutes);

        if (plans[i].data_limit == -1)
            strcpy(data_limit_display, "Unlimited");
        else
            sprintf(data_limit_display, "%dMB", plans[i].data_limit);

        printf("Plan %d: %s\n", i + 1, plans[i].name);
        printf(" Rate per minute: $%.2f\n", plans[i].rate_per_minute);
        printf(" Free Minutes: %s\n", free_minutes_display);
        printf(" Data Limit: %s\n", data_limit_display);
        printf(" Price: $%.2f/month\n", plans[i].rate_per_minute * 30); // Assuming 30 days in a month
        printf("-----------------------------\n");
    }
}

void Add_New_Plan()
{
    if (plan_count >= MAX_PLANS)
    {
        printf("Plan limit reached. Cannot add more plans.\n");
        return;
    }
    printf("Enter plan name: ");
    scanf("%s", plans[plan_count].name);
    printf("Enter rate per minute: ");
    scanf("%f", &plans[plan_count].rate_per_minute);
    printf("Enter free minutes (-1 for unlimited): ");
    scanf("%d", &plans[plan_count].free_minutes);
    printf("Enter data limit in MB (-1 for unlimited): ");
    scanf("%d", &plans[plan_count].data_limit);
    plan_count++;
    printf("Plan added successfully.\n");
    // Database saving will be handled in main or a dedicated function
}