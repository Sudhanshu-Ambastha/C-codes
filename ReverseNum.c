#include <stdio.h>

int main() {
    int n, a, b, c, sum;
    
    printf("Enter no.: ");
    scanf("%d", &n);
    
    a = n %10;
    b = n % 100 /10;
    c = n /100;
    
    printf("%d%d%d", a, b, c);
    
    return 0;
}
