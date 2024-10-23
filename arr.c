#include <stdio.h>

int main() {
    int arr[5]={5,7,9,10,8};
    printf("%d\n",arr[3]);
    printf("%d\n",sizeof(arr));
    printf("%d",sizeof(arr[0]));
    
    for(int i=0;i<=5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}