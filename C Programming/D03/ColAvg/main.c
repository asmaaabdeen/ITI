#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[4][6] = {{2,5,4,6,9,7},
                  {10,20,30,40,50,60},
                  {1,2,3,4,5,6},
                  {11,12,13,14,15,16}};
   int Avg[6]={0};
   int i,j;
   for(i=0;i<4;i++){
    for(j=0;j<6;j++){
        Avg[j]+= arr[i][j];
    }
   }
   for(i=0;i<6;i++){
    Avg[i]=Avg[i]/4;
   }
   for(i=0;i<6;i++){
    printf("Avarage of Column %d = %d \n",i+1,Avg[i]);
   }
    return 0;
}
