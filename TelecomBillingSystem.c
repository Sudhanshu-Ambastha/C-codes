#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CUSTOMERS 100
#define MAX_PLANS 10

struct Plan
{
    char name[50];
    float rate_per_minute;
    int free_minutes;
    int data_limit;
};

struct Customer
{
    char name[100];
    char phone[15];
    int call_duration;
    float bill_amount;
    struct Plan selected_plan;
};

struct Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

struct Plan plans[MAX_PLANS] = {
    {"Basic", 0.50, 50, 500},
    {"Standard", 0.30, 200, 2000},
    {"Premium", 0.20, 500, 10000},
    {"Unlimited", 1.00, -1, -1}};

int plan_count = 4;

void Add_Customer();
void Remove_Customer();
void Display_Customers();
void Calculate_Bill();
void Search_Customer();
void Sort_Customers();
void Display_Plans();
void Add_New_Plan();
void Generate_Bill();
void Update_Customer();
void Filter_Customers_By_Plan();

int main()
{
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
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Add_Customer();
            break;
        case 2:
            Remove_Customer();
            break;
        case 3:
            Display_Customers();
            break;
        case 4:
            Calculate_Bill();
            break;
        case 5:
            Search_Customer();
            break;
        case 6:
            Sort_Customers();
            break;
        case 7:
            Display_Plans();
            break;
        case 8:
            Add_New_Plan();
            break;
        case 9:
            Generate_Bill();
            break;
        case 10:
            Update_Customer();
            break;
        case 11:
            Filter_Customers_By_Plan();
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    return 0;
}

int Is_Valid_Phone_Number(const char *phone)
{
    if (strlen(phone) != 10)
        return 0;

    for (int i = 0; i < 10; i++)
    {
        if (!isdigit(phone[i]))
            return 0;
    }
    return 1;
}

float Get_Discounted_Price(float price, int months)
{
    if (months >= 12)
        return price * 0.95; // 5% off for yearly subscription
    return price;
}

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
        printf("  Rate per minute: $%.2f\n", plans[i].rate_per_minute);
        printf("  Free Minutes: %s\n", free_minutes_display);
        printf("  Data Limit: %s\n", data_limit_display);
        printf("  Price: $%.2f/month\n", plans[i].rate_per_minute * 30); // Assuming 30 days in a month
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
}

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

            customers[i].call_duration += call_duration; // Update total call duration
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
                customers[i].bill_amount += chargeable_minutes * rate; // Calculate bill based on updated duration
            }

            printf("Bill updated for %s. Total Amount: $%.2f\n", name, customers[i].bill_amount);
            return;
        }
    }
    printf("Customer not found.\n");
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
                    int free_minutes = customers[i].selected_plan.free_minutes;
                    float rate = customers[i].selected_plan.rate_per_minute;

                    if (free_minutes == -1 || new_duration <= free_minutes)
                    {
                        customers[i].bill_amount = 0.0;
                    }
                    else
                    {
                        int chargeable_minutes = new_duration - free_minutes;
                        customers[i].bill_amount = chargeable_minutes * rate;
                    }
                    printf("Call duration updated successfully. Total Bill Amount: $%.2f\n", customers[i].bill_amount);
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