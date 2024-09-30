#include <stdio.h>

int factorialNum(){
    int n, i, factorial = 1;
    printf("Input the number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
        
    } else {
        for (i = 1; i <= n; i++) {
            factorial *= i;
            
        }
        printf("The Factorial of %d is: %llu\n", n, factorial);
        
    }
    return 0;
}
int main() {
    int a;
    a=factorialNum();
    return 0;
}