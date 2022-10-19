#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
     printf("please enter 1st num \n");
    scanf("%d",x);
    printf("\n");
    int y;
    printf("please enter 2nd num \n");
    scanf("%d",y);
    printf("\n");
    int xor = x ^ y;
    int and = x & y;
    int or = x|y;
    printf("%d xor %d = %d \n",x,y,xor);
     printf("%d and %d = %d \n",x,y,and);
      printf("%d or %d = %d \n",x,y,or);
    return 0;
}
