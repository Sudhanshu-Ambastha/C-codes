#include <stdio.h>

int main() {
    int num, reversedNum = 0, remainder, originalNum;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num; 

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    (originalNum == reversedNum) ? printf("%d is a palindrome.\n", originalNum) : printf("%d is not a palindrome.\n", originalNum);

    return 0;
}