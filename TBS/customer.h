#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "plan.h" // Include Plan definition

#define MAX_CUSTOMERS 100

struct Customer
{
    char name[100];
    char phone[15];
    int call_duration;
    float bill_amount;
    struct Plan selected_plan;
};

extern struct Customer customers[MAX_CUSTOMERS];
extern int customer_count;

void Add_Customer();
void Remove_Customer();
void Display_Customers();
void Search_Customer();
void Sort_Customers();
void Update_Customer();
void Filter_Customers_By_Plan();

#endif