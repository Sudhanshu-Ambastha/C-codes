#include <stdio.h>

//call by value
void addByValue(int x){
    x += 10;
    printf("call by value:%d\n",x);
}

//call by reference
void addByReference(int * x){
    *x+=10;
    printf("call by reference:%d\n",*x);
}

int main() {
    // call by value
    int a =20,b=20;
    printf("Before call by value:%d\n", a);
    addByValue(a);
    printf("After call by value:%d\n", a);
    
    //call by reference 
    printf("Before call by reference:%d\n",b);
    addByReference(&b);
    printf("After call by reference:%d\n", b);

    return 0;
}