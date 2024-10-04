#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sp = n - 1;
    int st = 1;
    int rows = 2 * n - 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < sp; j++) {
            printf(" ");
        }
        for (int j = 0; j < st; j++) {
            printf("*");
        }

        if (i < rows / 2) {
            sp--;
            st += 2;
        } else {
            sp++;
            st -= 2;
        }
        printf("\n");
    }

    return 0;
}