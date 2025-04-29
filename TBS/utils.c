#include "utils.h"
#include <string.h>
#include <ctype.h>

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
        return price * 0.95;
    return price;
}