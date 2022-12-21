#include <stdio.h>
#include <stdlib.h>

int main()
{
int x,sum=0;
do{
    scanf("%d",&x);
    sum+=x;
}while(sum<100);
printf("%d",sum);
}
