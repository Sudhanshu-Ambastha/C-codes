#include <stdio.h>
#include <stdlib.h>

struct bankdata {
    int AN;
    char name[30];
    int BAL;
};

int main() {
    struct bankdata C[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter account number for customer %d: ", i + 1);
        scanf("%d", &C[i].AN);
        getchar(); // Clear newline character left by scanf
        
        printf("Enter name for customer %d: ", i + 1);
        fgets(C[i].name, sizeof(C[i].name), stdin);

        printf("Enter balance for customer %d: ", i + 1);
        scanf("%d", &C[i].BAL);
    }

    for (int i = 0; i < 10; i++) {
        printf("\nCustomer %d:\n", i + 1);
        printf("Account Number: %d\n", C[i].AN);
        printf("Name: %s", C[i].name); // fgets adds newline automatically
        printf("Balance: %d\n", C[i].BAL);
    }

    return 0;
}