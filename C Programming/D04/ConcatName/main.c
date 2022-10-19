#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("please enter your first name ");
    char fname[10],lname[10];

       gets(fname);
     printf("please enter your last name ");
  gets(lname);
    printf("\n your full name is ");
    strcat(fname," ");
    strcat(fname,lname);
    puts(fname);
    return 0;
}
