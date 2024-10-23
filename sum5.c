#include <stdio.h>

int main() {
    int n[5];
    int sum=0;
    printf("Enter no.: \n");
    for(int i=0;i<5;i++){
        scanf("%d",&n[i]);
        sum=sum+n[i];
    }
    printf("sum of 5 no.s: %d",sum);
    return 0;
}