#include <stdio.h>
#include <math.h>

int main() {
    int num, rev = 0, temp, firstDigit, lastDigit, digits;

    printf("Enter any number: ");
    scanf("%d", &num);

    temp = num;
    digits = (int)log10(num) + 1;
    lastDigit = num % 10;
    firstDigit = num / pow(10, digits - 1);
    rev = (lastDigit * pow(10, digits - 1)) + (num % (int)pow(10, digits - 1)) - lastDigit + firstDigit;

    printf("Original number = %d\n", num);
    printf("Number after swapping first and last digits: %d\n", rev);

    return 0;
}
