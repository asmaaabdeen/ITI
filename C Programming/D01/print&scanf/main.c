#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");

    int x ;
    char ch;
printf("please enter a character ");
    scanf("%c",&ch);
    printf("the asci value of %c is %d ",ch,ch);
    printf("\n");
     printf("please enter a number ");
    scanf("%d",&x);
    printf("the char equivalent to %d is %c",x,x);
    printf("\n");
    printf("the hexa value of %d is %x",x,x);


    return 0;
}
