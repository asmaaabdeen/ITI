#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void gotoxy (int column, int line){
COORD coord;
coord.X = column;
coord.Y = line;
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{

int C,R,i;
int n;
printf("please enter an odd number \n" );
scanf("%d",&n);

C=(n+1)/2;
R=1;

for (i=1;i<=n*n;i++){

gotoxy(C*3,R*3);
printf("%d",i);

if(i%n==0)
    {
 R++;

 if (R>n)
            R=1;


    }
else
    {
R--; C--;
if(R<1)
    R=n;



if(C<1)
    C=n;



    }
}
}

