#include <stdio.h>

// Method 1: Reverse using a temporary variable by swapping digits manually
int reverseWithTemp(int num) {
    int temp = num;  
    int rev = 0;     
    while (temp > 0) {
        int lastDigit = temp % 10;  // Extract last digit
        rev = rev * 10 + lastDigit; // Build reversed number
        temp /= 10;                 // Remove last digit
    }
    return rev;
}

// Method 2: Reverse using only two variables (num and rev)
int reverseWithTwoVars(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

// Method 3: Reverse using the mathematical formula remainder * 10 + num
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

    printf("Reversed (Using Temp Variable with Swap Logic): %d\n", reverseWithTemp(num));
    printf("Reversed (Using Only Two Variables): %d\n", reverseWithTwoVars(num));
    printf("Reversed (Using Math Formula): %d\n", reverseUsingMath(num));

    return 0;
}