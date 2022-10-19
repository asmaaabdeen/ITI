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
C=(3+1)/2;
R=1;

for (i=1;i<=9;i++){

gotoxy(C*3,R*3);
printf("%d",i);

if(i%3==0)
    {
 R++;
        if (R>3)
            R=1;




    }
else
    {
R--; C--;
if(R<1)
    R=3;



if(C<1)
    C=3;



    }
}
}
