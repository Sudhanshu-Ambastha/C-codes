#include <stdio.h>

int main() {
    int n, rows;
    
    printf("Enter num: ");
    scanf("%d", &n);
    
    rows = (n + 1) / 2;  // Initialize rows after input

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n - 1) {
                printf("*\t");  // Print "*"
            } else {
                printf("\t");   // Print space
            }
        }
        printf("\n");  // Move to next line after each row
    }

    return 0;
}
