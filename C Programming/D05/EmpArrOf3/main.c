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
struct Employee {
    int id,age;
    char gender,name[100],adress[200];
    double salary,overtime,deduct;
};
struct Employee E[3];

void New(){
     int i;
    for (i=0;i<3;i++){
system("cls");
 char EData[8][9]={"ID","Age","Gender","Name","Address","Salary","overtime","deduct"};

   int j;
    for (j=0;j<8;j++){
            if (j<4){
           gotoxy(10,5+(3*j));
   printf("%s",EData[j]);}
   else
{
      gotoxy(40,5+(3*(j-4)));
   printf("%s",EData[j]);
}
    }

   gotoxy(18,5);
   scanf("%d",&E[i].id);
 gotoxy(18,8);
   scanf("%d",&E[i].age);
    gotoxy(18,11);
    _flushall();
   scanf("%c",&E[i].gender);
    gotoxy(18,14);
    _flushall();
  gets(E[i].name);
    gotoxy(50,5);
   gets(E[i].adress);
    gotoxy(50,8);
   scanf("%lf",&E[i].salary);
    gotoxy(50,11);
   scanf("%lf",&E[i].overtime);
   gotoxy(50,14);
   scanf("%lf",&E[i].deduct);

    }
}
void display(){
    system("cls");
    int i ;
    for (i=0;i<3;i++){

printf("Employee ID : %d \n",E[i].id);
printf("name : ");puts(E[i].name);
printf("NetSalary = %lf EGP \n",E[i].salary+E[i].overtime-E[i].deduct);

    }
_getch();
}
int main()
{

    char ch, menu[3][9] ={"New","Display","Exit"};
    int i,current=0 ,ExitFlag=0 ;
do{
    textattr(NormalPen);
        system("cls");
for(i=0;i<3;i++){

        if (current == i)
        textattr(HighlightPen);
else textattr(NormalPen);
        gotoxy(55,10+(3*i));
  _cprintf("%s",menu[i]);
}

ch = getch();
switch(ch){
case Enter:
    switch(current){
case 0: //New
    New();
    break;
case 1: //Display
    display();
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
