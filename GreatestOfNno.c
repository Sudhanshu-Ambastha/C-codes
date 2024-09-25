#include <stdio.h>

int main() {
    int n, num, greatest, i = 1;

    printf("Enter how many numbers you want to compare: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a number greater than 0.\n");
        return 1;
    }

    printf("Enter number 1: ");
    scanf("%d", &greatest);  

    do {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num > greatest) {
            greatest = num;
        }
        i++;
    } while (i < n); 

    printf("The greatest number is: %d\n", greatest);

    return 0;
}