#include <stdio.h>
#include <math.h>

int prime(int n) {
    int p = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            p = 0;
            break;
        }
    }
    if (p == 1)
        return n;
    else
        return 1;
}

int fact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact = fact * prime(i);

    printf("The Prime factorial of %d is %d", n, fact);
}

int main() {
    int num;
    printf("Enter the number : ");
    scanf("%d", &num);
    fact(num);
    return 0;
}