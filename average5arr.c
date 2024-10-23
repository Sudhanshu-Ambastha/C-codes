#include <stdio.h>

int main() {
    int n[5];
    int sum = 0;
    float average;
    
    printf("Enter 5 numbers: \n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &n[i]);
        sum = sum + n[i]; 
    }
    
    average = sum / 5.0;
    printf("Average of 5 numbers: %.2f", average);
    
    return 0;
}