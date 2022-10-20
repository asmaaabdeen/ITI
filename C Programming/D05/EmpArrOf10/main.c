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
struct Employee E[10];

void New(int idx ){
    int ovrrd;
if (E[idx].id!=0&&E[idx].salary!=0){
     printf("the index is already  allocated do you want to override the old data or exit ? press 0 to exit or 1 to override ");

     scanf("%d",&ovrrd);
           if (ovrrd==0){
               _getch();
           }
else if (ovrrd==1)
form(idx);
}
else form(idx);
}
void form(int idx){

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
int x,k;
   gotoxy(18,5);
   scanf("%d",&x);
   if(x<=0 ){
    system("cls");
     printf("the id has to be greater than 0");
     _getch();
   }

   else{

     E[idx].id=x;
 gotoxy(18,8);
   scanf("%d",&E[idx].age);
    gotoxy(18,11);
    _flushall();
   scanf("%c",&E[idx].gender);
    gotoxy(18,14);
    _flushall();
  gets(E[idx].name);
    gotoxy(50,5);
   gets(E[idx].adress);
    gotoxy(50,8);
   scanf("%lf",&E[idx].salary);
    gotoxy(50,11);
   scanf("%lf",&E[idx].overtime);
   gotoxy(50,14);
   scanf("%lf",&E[idx].deduct);}

   }



void displayAll(){
    system("cls");

    int i ,flag=0;
    for (i=0;i<10;i++){
if(E[i].salary!=0){
    printf("Employee ID : %d \n",E[i].id);
printf("name : ");puts(E[i].name);
printf("NetSalary = %lf EGP \n",E[i].salary+E[i].overtime-E[i].deduct);
flag=1;
}

    }
    if(flag==0)
        printf("no employees to show");
_getch();
}
void displayByID(int id){
    system("cls");
    int i, flag =0;
    for (i=0;i<10;i++){
        if(id==E[i].id){

printf("Employee ID : %d \n",E[i].id);
printf("name : ");puts(E[i].name);
printf("NetSalary = %lf EGP \n",E[i].salary+E[i].overtime-E[i].deduct);
flag = 1;
           }

    }
    if (flag ==0)
        printf("this id does not exist");
_getch();
}
void deleteByID(int id){
 int i,flag =0;;
    for (i=0;i<10;i++){
        if(id==E[i].id){
E[i].salary=0;
flag = 1;
printf("the employee has been deleted");
           }

    }
     if (flag ==0)
        printf("this id does not exist");
_getch();
}

void deleteByName(){
    system("cls");
    printf("please enter the name of the employee you want to delete : ");
    char Name[100];
    _flushall();
    gets(Name);
 int i,flag =0;;
    for (i=0;i<10;i++){
        if(strcmp(Name,E[i].name)==0){
E[i].salary=0;
flag = 1;
printf("the employee has been deleted");
           }

    }
     if (flag ==0)
        printf("this Name does not exist");
_getch();
}


int main()
{

    char ch, menu[6][20] ={"New","Display By ID","Display All","Delete By ID","Delete By Name","Exit"};
    int i,current=0 ,ExitFlag=0 ;
do{
    textattr(NormalPen);
        system("cls");
for(i=0;i<6;i++){

        if (current == i)
        textattr(HighlightPen);
else textattr(NormalPen);
        gotoxy(10,2+(3*i));
  _cprintf("%s",menu[i]);
}

ch = getch();
switch(ch){
case Enter:
    switch(current){
case 0: //New
    system("cls");
    printf("Please Enter The Index You Want To Add New Employee In (it must be from 0to9) : ");
    int indx;
    scanf("%i",&indx);
    printf("\n");
    New(indx);
    break;
case 1: //DisplayByID
     system("cls");
    printf("please enter an ID : ");
    int id;
    scanf("%d",&id);
    if(id<=0){
         printf("the id has to be a positive number");
         _getch();
    }

    else
    displayByID(id);
    break;
case 2 : //displayAll
    displayAll();
    break;
    case 3: //DeleteById
        system("cls");
    printf("Please Enter The Id Of The Employee You Want To Delete: ");
    int ID;
    scanf("%i",&ID);
    if(ID<=0){
         printf("the id has to be a positive number");
         _getch();
    }
    else
        deleteByID(ID);
    break;
case 4: //DeleteByName
  deleteByName();
    break;
case 5://Exit
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
    if(current <0) current = 5;
    break;
case 80: //down
    current ++;
    if(current >5) current = 0;
    break;
case 71: //home
    current = 0;
    break;
case 79: //end
     current = 5;
    break;
    }
break;

}
}while(!ExitFlag);

    return 0;
}
