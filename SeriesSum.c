#include <stdio.h>
#include <math.h>

// Function to calculate factorial of a number
long long factorial(int num) {
    long long fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of the series
double sum_of_series(int x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double) (pow(x, i)) / factorial(i);
    }
    return sum;
}

int main() {
    int x, n;
    
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the number of terms (n): ");
    scanf("%d", &n);

    double result = sum_of_series(x, n);
    printf("The sum of the series is: %.2f\n", result);

    return 0;
}

