#include <stdio.h>

void reverseNumber(int num)
{
    int reversed = 0;
    for (; num != 0; num /= 10)
    {
        reversed = reversed * 10 + num % 10;
    }
    printf("Reversed number: %d\n", reversed);
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    reverseNumber(num);

    return 0;
}
