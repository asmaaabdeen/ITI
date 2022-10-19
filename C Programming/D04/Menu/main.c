#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define NormalPen 0x0b
#define HighlightPen 0xb0
#define Enter 0x0d
#define Esc  27

void gotoxy (int column, int line){
COORD coord;
coord.X = column;
coord.Y = line;
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void textattr (int i){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

int main()
{
    char ch, menu[3][5] ={"New","Save","Exit"};
    int i,current=0 ,ExitFlag=0 ;
do{
    textattr(NormalPen);
        system("cls");
for(i=0;i<3;i++){
        if (current == i)
        textattr(HighlightPen);
else textattr(NormalPen);
        gotoxy(55,10+(3*i));
       printf("%s",menu[i]);
}

ch = getch();
switch(ch){
case Enter:
    switch(current){
case 0: //New
    system("cls");
    printf("please enter something");
    _getch();
    break;
case 1: //Save
    system("cls");
    printf("Saved");
    _getch();
    break;
case 2 : //Exit
    ExitFlag = 1;
    break;
    }
    break;
case Esc:
    ExitFlag = 1;
    break;
case -32:
    ch = getch();
    switch(ch){
case 72: //up
    current --;
    if(current <0) current = 2;
    break;
case 80: //down
    current ++;
    if(current >2) current = 0;
    break;
case 71: //home
    current = 0;
    break;
case 79: //end
     current = 2;
    break;
    }
break;

}
}while(!ExitFlag);

    return 0;
}
