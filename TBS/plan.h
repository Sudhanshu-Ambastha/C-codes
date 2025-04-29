#ifndef PLAN_H
#define PLAN_H

#define MAX_PLANS 10

struct Plan
{
    char name[50];
    float rate_per_minute;
    int free_minutes;
    int data_limit;
};

extern struct Plan plans[MAX_PLANS];
extern int plan_count;

void Display_Plans();
void Add_New_Plan();

#endif