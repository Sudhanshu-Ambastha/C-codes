// Online C compiler to run C program online
#include <stdio.h>

int main() {
    char ch; float a, b, sum;
    
    printf("Enter an operator (+, -, *, /):");
    scanf("%c", &ch);
    printf("Enter 1st no.: ");
    scanf("%f", &a);
    printf("Enter 2nd no.: ");
    scanf("%f", &b);
    
    switch(ch){
        case '+':
        sum = a + b;
        printf("%.2f + %.2f = %.2f\n", a, b, sum);
        break;
        case'-':
        sum = a - b;
        printf("%.2f - %.2f = %.2f\n", a, b, sum);
        break;
        case'*':
        sum = a * b;
        printf("%.2f * %.2f = %.2f\n", a, b, sum);
        break;
        case'/':
         if (a || b != 0)
        {
            sum = a / b;
            printf("%.2f / %.2f = %.2f\n", a, b, sum);
        }
        else
        {
            printf("Error! Division by zero.\n");
        }
        break;
        default:
        printf("Invalid operator!\n");
    }

    return 0;
}
