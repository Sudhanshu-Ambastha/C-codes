#include <stdio.h>
#include <math.h>  // For using sqrt()

int main() {
    long long num;
    int isPrime = 1;  // Assume prime

    // Input from user
    printf("Enter a positive integer: ");
    scanf("%lld", &num);

    // Prime check logic
    if (num <= 1) {
        isPrime = 0;  // Numbers <= 1 are not prime
    } else if (num == 2) {
        isPrime = 1;  // 2 is prime
    } else if (num % 2 == 0) {
        isPrime = 0;  // Even numbers > 2 are not prime
    } else {
        for (long long i = 3; i <= sqrt(num); i += 2) {  // Check only odd numbers
            if (num % i == 0) {
                isPrime = 0;  
            }
        }
    }

    // Output result
    if (isPrime)
        printf("%lld is a prime number.\n", num);
    else
        printf("%lld is not a prime number.\n", num);

    return 0;
}