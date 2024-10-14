#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int checkSumOfTwoPrimes(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            printf("%d = %d + %d\n", num, i, num - i);
            return 1;
        }
    }
    return 0;
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    if (checkSumOfTwoPrimes(num)) {
        printf("Yes, the number %d can be expressed as the sum of two prime numbers.\n", num);
    } else {
        printf("No, the number %d cannot be expressed as the sum of two prime numbers.\n", num);
    }

    return 0;
}