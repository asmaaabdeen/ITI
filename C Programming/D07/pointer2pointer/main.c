#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int **marks,*sum,*avg,stdN,subN;

    printf("please enter the number of students : ");
    scanf("%d",&stdN);
    printf("please enter the number of subjects : ");
    scanf("%d",&subN);
    printf("*-----------------------------------------------------------*");

    sum = (int*) malloc(stdN*sizeof(int));
    avg = (int*) malloc(subN*sizeof(int));
    marks = (int**) malloc(stdN*sizeof(int*));

    for (i=0;i<stdN;i++){
        marks[i] = (int*) malloc(subN*sizeof(int));
    }


     for(i=0;i<stdN;i++)
        sum[i]=0;
     for(i=0;i<subN;i++)
        avg[i]=0;


    for(i=0;i<stdN;i++){
        for(j=0;j<subN;j++){

            printf("\n please enter student %d subject %d grade ",i+1,j+1);
            _flushall();
            scanf("%d",&marks[i][j]);
sum[i]+=marks[i][j];
avg[j]+=marks[i][j];
        }
    }
   for(i=0;i<subN;i++)
        avg[i]/=stdN;

    for(i=0;i<subN;i++)
        printf("average subject %i = %d \n",i+1,avg[i]);

    for(i=0;i<stdN;i++)
        printf("sum subject for student %i = %d \n",i+1,sum[i]);
free(avg);free(sum);free(marks);



    return 0;
}
