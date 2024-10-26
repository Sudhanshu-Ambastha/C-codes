#include <stdio.h>
#include <string.h>

int main() {
   char a[6]="hello";
   char b[]="world";
   printf("string:%s\n",a);
   printf("string:%s\n",b);
   
   strcat(a,b);
   printf("%s\n",a);
   
   strlen(a);
   printf("%s\n",a);
   
   strcpy(a,b);
   printf("%s\n",a);
   
   strcmp(a,b);
   printf("%s\n",a,b);
   
    return 0;
}