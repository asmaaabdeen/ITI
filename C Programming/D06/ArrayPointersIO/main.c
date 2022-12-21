#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,arr[4];
   arrPtr=arr;
   for(i=0;i<4;i++){
    printf("please enter value %i ",i+1);
    scanf("%i",arr+i);
   }
   for(i=0;i<4;i++){
    printf("value %i = %i \n",i+1,*(arr+i));

   }
    return 0;
}
