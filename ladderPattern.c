#include <stdio.h>

int main() {
    int col, row;
    
    printf("Enter col: ");
    scanf("%d", &col);
    
    printf("Enter row: ");
    scanf("%d", &row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if ((i % 3 == 0 && i != 0) || j == 0 || j == col - 1 || i == 0) {
                printf("*\t");
            } else {
                printf(" \t");
            }
        }
        printf("\n");
    }
}
