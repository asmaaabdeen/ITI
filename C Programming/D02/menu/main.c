#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
      char z;
    printf("\n please enter an operator \n");
  scanf("%c",&z);
  printf("please enter two numbers \n");
  scanf("%d%d",&x,&y);


  switch(z){
  case '+':
    printf("%d",x+y);
  break;
  case '*':
       printf("%d",x*y);
    break;
    case '/':
       printf("%d",x/y);
    break;
    default :
        printf("%d%d",x,y);
  }
  }


