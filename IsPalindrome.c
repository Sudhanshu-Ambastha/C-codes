#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i, length;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    length = strlen(str);

    for (i = 0; i < length / 2; i++){
        if (str[i] != str[length - 1 - i]){
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome){
        printf("The string is a palindrome.\n");
    }else{
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
