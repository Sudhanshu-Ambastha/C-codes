#include <stdio.h>

int main() {
    int a[5];
    int largest, smallest;
    printf("Enter elements: ");
    for(int i=0; i<5;i++){
        scanf("%d",&a[i]);
    }
    largest=smallest=a[0];
    for(int i=0; i<5;i++){
        if(a[i]>largest){
            largest=a[i];
        }else{
            smallest=a[i];
        }
    } printf ("largest:%d and smallest:%d",largest,smallest);

    return 0;
}
