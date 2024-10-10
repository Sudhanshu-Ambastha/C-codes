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

    return (sum == originalNum);
}

int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    if (isPrime(number)) {
        printf("%d is a Prime number.\n", number);
    } else {
        printf("%d is not a Prime number.\n", number);
    }

    return 0;
}
