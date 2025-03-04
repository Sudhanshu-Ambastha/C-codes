#include <stdio.h>

// Method 1: Reverse using a temporary variable
int reverseWithTemp(int num) {
    int temp = num, rev = 0;
    while (temp > 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return rev;
}

// Method 2: Reverse without a temporary variable (in-place swap)
int reverseWithoutTemp(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

// Method 3: Reverse using remainder and a mathematical formula
int reverseUsingMath(int num) {
    int rev = 0, remainder;
    while (num > 0) {
        remainder = num % 10;
        rev = rev * 10 + remainder;
        num /= 10;
    }
    return rev;
}

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed (Using Temp Variable): %d\n", reverseWithTemp(num));
    printf("Reversed (Without Temp Variable): %d\n", reverseWithoutTemp(num));
    printf("Reversed (Using Math Formula): %d\n", reverseUsingMath(num));

    return 0;
}