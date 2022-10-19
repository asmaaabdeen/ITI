#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10],i,j;
   for(i=0;i<10;i++){
    printf("please enter number %i ",i+1);
    scanf("%d",&arr[i]);

   }
int max = arr[0];
for(i=0;i<10;i++){
    if(arr[i]>max)
        max = arr[i];
}

    printf("Maximum number is %d \n",max);


    int min=arr[0];
    for(i=0;i<10;i++){
        if (arr[i]<min)
            min = arr[i];
    }
    printf("Minimum number is %d",min);
    return 0;
}
