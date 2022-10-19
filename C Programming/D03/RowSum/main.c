#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[4][6] = {{2,5,4,6,9,7},{10,20,30,40,50,60},{1,2,3,4,5,6},{11,12,13,14,15,16}};
   int sum[4]={0};
   int i,j;
   for(i=0;i<4;i++){
    for(j=0;j<6;j++){
        sum[i]+= arr[i][j];
    }
   }
   for(i=0;i<4;i++){
    printf("sum of row %d = %d \n",i+1,sum[i]);
   }
    return 0;
}
