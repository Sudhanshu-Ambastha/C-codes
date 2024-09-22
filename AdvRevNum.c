/* reverse 8-digit number, and generate a reverse number of 3rd, 4th,
and 5th digits.*/
#include <stdio.h>

int main() {
    int n, a, b, c, sum;
    
    printf("Enter no.: ");
    scanf("%d", &n);
    
    n = n %1000000 /1000;
    a = n %10;
    b = n % 100 /10;
    c = n /100;
    
    printf("%d%d%d", a, b, c);
    
    return 0;
}
