#include <stdio.h>
#include <stdlib.h>
void ValueSwap(int x,int y){
int temp=x;
x=y;
y=temp;

}
void AddressSwap(int* x,int* y){
int temp=*x;
*x=*y;
*y=temp;
}
int main()
{

  int x,y;
  printf("please enter the numbers you want to swap :\n");
  printf("x = ");
  scanf("%i",&x);
  printf("y = ");
  scanf("%i",&y);
  ValueSwap(x,y);
  printf("using swap by value x = %i and y = %i \n",x,y);
  AddressSwap(&x,&y);
  printf("using swap by address x = %i and y = %i \n",x,y);
    return 0;
}
