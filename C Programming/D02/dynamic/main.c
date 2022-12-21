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
do {
    printf("please enter an odd positive number \n" );
scanf("%d",&n);

}while(n%2==0 || n<1);

C=(n+1)/2;
R=1;

for (i=1;i<=n*n;i++){

gotoxy(C*4,R*6);
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

