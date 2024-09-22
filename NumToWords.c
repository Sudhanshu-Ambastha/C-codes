#include <stdio.h>

int main() {
    int num, tens, ones;

    // Input a 2-digit number
    printf("Input an integer no (2 digits): ");
    scanf("%d", &num);

    // Check if the number is within the 2-digit range
    if (num < 10 || num > 99) {
        printf("Please enter a valid 2-digit number.\n");
        return 1;
    }

    // Extract the tens and ones place
    tens = num / 10;
    ones = num % 10;

    // Handle the tens place
    if (tens == 1) {
        // Special case for numbers between 10 and 19
        if (ones == 0) printf("Your number is: Ten\n");
        else if (ones == 1) printf("Your number is: Eleven\n");
        else if (ones == 2) printf("Your number is: Twelve\n");
        else if (ones == 3) printf("Your number is: Thirteen\n");
        else if (ones == 4) printf("Your number is: Fourteen\n");
        else if (ones == 5) printf("Your number is: Fifteen\n");
        else if (ones == 6) printf("Your number is: Sixteen\n");
        else if (ones == 7) printf("Your number is: Seventeen\n");
        else if (ones == 8) printf("Your number is: Eighteen\n");
        else if (ones == 9) printf("Your number is: Nineteen\n");
    } else {
        // For numbers 20 and above
        printf("Your number is: ");

        // Print the tens place
        if (tens == 2) printf("Twenty ");
        else if (tens == 3) printf("Thirty ");
        else if (tens == 4) printf("Forty ");
        else if (tens == 5) printf("Fifty ");
        else if (tens == 6) printf("Sixty ");
        else if (tens == 7) printf("Seventy ");
        else if (tens == 8) printf("Eighty ");
        else if (tens == 9) printf("Ninety ");

        // Print the ones place
        if (ones == 1) printf("One\n");
        else if (ones == 2) printf("Two\n");
        else if (ones == 3) printf("Three\n");
        else if (ones == 4) printf("Four\n");
        else if (ones == 5) printf("Five\n");
        else if (ones == 6) printf("Six\n");
        else if (ones == 7) printf("Seven\n");
        else if (ones == 8) printf("Eight\n");
        else if (ones == 9) printf("Nine\n");
        else if (ones == 0) printf("\n"); // For round tens (e.g. 20, 30)
    }

    return 0;
}
