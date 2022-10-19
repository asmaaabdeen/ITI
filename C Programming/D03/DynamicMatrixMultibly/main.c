#include <stdio.h>
#include <stdlib.h>

int main()
{
   int r1,cr,c2;
   printf("please enter # of rows for first matrix ");
   scanf("%d",&r1);
    printf("please enter # of [columns for first matrix&rows for the second matrix] ");
    scanf("%d",&cr);
     printf("please enter # of columns for second matrix ");
     scanf("%d",&c2);

     int m1[r1][cr],i,j,k;
     for(i=0;i<r1;i++){
        for(j=0;j<cr;j++){
            printf("please enter first matrix row %d column %d ",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }
     }
     int m2[cr][c2];
      for(i=0;i<cr;i++){
        for(j=0;j<c2;j++){
            printf("please enter second matrix row %d column %d ",i+1,j+1);
            scanf("%d",&m2[i][j]);
        }
     }
     int result[r1][c2] ;
     for(i=0;i<r1;i++){
        for(j=0;j<c2;j++)
            result[i][j]=0;
     }

     for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
                for(k=0;k<cr;k++)
            result[i][j]+=m1[i][k]*m2[k][j];
        }
    }


    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
             printf("%d \t" , result[i][j]);
        }
           printf("\n");

    }
    return 0;
}
