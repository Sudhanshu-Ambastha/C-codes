#include <stdio.h>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;  
    }
    return result;
}

int isArmstrong(int num) {
    int originalNum = num;
    int sum = 0;
    int digits = countDigits(num); 

    while (num != 0) {
        int remainder = num % 10;    
        sum += power(remainder, digits); 
        num /= 10;                    
    }

    return (sum == originalNum);      }

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
