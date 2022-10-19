#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[10],i;
   for(i=0;i<10;i++){
    printf("please enter number %i ",i+1);
    scanf("%d",&arr[i]);
    printf("\n");
   }
    for(i=0;i<10;i++){
    printf("number %i = %i",i+1,arr[i]);
    printf("\n");
   }
    return 0;
}
