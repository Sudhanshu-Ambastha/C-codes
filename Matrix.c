#include <stdio.h>

void addMatrices(int a[2][2], int a2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = a[i][j] + a2[i][j];
        }
    }
}

void subtractMatrices(int a[2][2], int a2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = a[i][j] - a2[i][j];
        }
    }
}

void multiplyMatrices(int a[2][2], int a2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = a[i][j] * a2[i][j];
        }
    }
}

void divideMatrices(int a[2][2], int a2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[2][2] != 0 && a2[i][j] != 0) { 
                result[i][j] = a[i][j] / a2[i][j];
            } else {
                printf("Division by zero at element [%d][%d]!\n", i, j);
                result[i][j] = 0; 
            }
        }
    }
}

void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int a2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    printf("Addition:\n");
    addMatrices(a, a2, result);
    printMatrix(result);

    printf("\nSubtraction:\n");
    subtractMatrices(a, a2, result);
    printMatrix(result);

    printf("\nMultiplication:\n");
    multiplyMatrices(a, a2, result);
    printMatrix(result);

    printf("\nDivision:\n");
    divideMatrices(a, a2, result);
    printMatrix(result);

    return 0;
}
