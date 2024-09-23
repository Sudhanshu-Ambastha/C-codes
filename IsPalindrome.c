#include <stdio.h>

int main() {
    char ch, str[100];  
    int num, digit1, digit2, digit3, reversed, isPalindrome = 1, length = 0;

    printf("Choose type (n for num / c for character): ");
    scanf(" %c", &ch);  // Added space before %c to ignore the newline left by the previous input

    switch(ch) {
        case 'n':  
            printf("Enter a 3-digit number: ");
            scanf("%d", &num);

            digit1 = num % 10;        
            digit2 = (num / 10) % 10;  
            digit3 = num / 100;      
            
            reversed = digit1 * 100 + digit2 * 10 + digit3;

            if (num == reversed)
                printf("%d is a palindrome.\n", num);
            else
                printf("%d is not a palindrome.\n", num);
            break;

        case 'c':  
            printf("Enter a string: ");
            scanf("%s", str);  
            
            while (str[length] != '\0') {
                length++;
            }

            for (int i = 0; i < length / 2; i++) {
                if (str[i] != str[length - 1 - i]) {
                    isPalindrome = 0; 
                    break;
                }
            }
            
            if (isPalindrome)
                printf("%s is a palindrome.\n", str);
            else
                printf("%s is not a palindrome.\n", str);
            break;

        default:
            printf("Not a valid choice.\n");
    }

    return 0;
}
