#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void gotoxy (int column, int line){
COORD coord;
coord.X = column;
coord.Y = line;
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct Employee {
    int id,age;
    char gender,name[100],adress[200];
    double salary,overtime,deduct;
};

int main()
{
    char EData[8][9]={"ID","Age","Gender","Name","Address","Salary","overtime","deduct"};
    struct Employee E;
    int i;
    for (i=0;i<8;i++){
            if (i<4){
           gotoxy(10,5+(3*i));
   printf("%s",EData[i]);}
   else
{
      gotoxy(40,5+(3*(i-4)));
   printf("%s",EData[i]);
}
    }

   gotoxy(18,5);
   scanf("%d",&E.id);
 gotoxy(18,8);
   scanf("%d",&E.age);
    gotoxy(18,11);
    _flushall();
   scanf("%c",&E.gender);
    gotoxy(18,14);
    _flushall();
  gets(E.name);
    gotoxy(50,5);
   gets(E.adress);
    gotoxy(50,8);
   scanf("%lf",&E.salary);
    gotoxy(50,11);
   scanf("%lf",&E.overtime);
   gotoxy(50,14);
   scanf("%lf",&E.deduct);

system("cls");
printf("Employee ID : %d \n",E.id);
printf("name : ");puts(E.name);
printf("NetSalary = %lf EGP",E.salary+E.overtime-E.deduct);
    return 0;
}
