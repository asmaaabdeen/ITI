#include <stdio.h>
#include <stdlib.h>

int main()
{
   int M1[3][2]={{1,2},
                 {3,4},
                {5,6}};

   int M2[2][1]={{1},
                {2}};

    int result[3][1] ={0};

    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<1;j++){
                for(k=0;k<2;k++)
            result[i][j]+=M1[i][k]*M2[k][j];
        }
    }


    for(i=0;i<3;i++){
        for(j=0;j<1;j++)
            printf("%d \n" , result[i][j]);
    }
    return 0;
}
