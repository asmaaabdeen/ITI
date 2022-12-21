#include <iostream>
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
     Employee* pNext;
     Employee* pPre;
    int id,age;
    char gender,name[100],adress[200];
    double salary,overtime,deduct;
};
///////////////////////////////////////////////////////////////////////////

class DoubleLinkedList{
    private:
 Employee* pStart;
 Employee* pLast;
public:
DoubleLinkedList (){
pStart = NULL;
pLast =NULL;
}


 Employee* NewEmp(){

    system("cls");

         Employee* E = new Employee();
        if(E == NULL)
            return 0;
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
/*int x,k;
   gotoxy(18,5);
   scanf("%d",&x);
   if(x<=0 ){
    system("cls");
     printf("the id has to be greater than 0");
     _getch();
   }*/



     gotoxy(18,5);
   scanf("%d",&E->id);
 gotoxy(18,8);
   scanf("%d",&E->age);
    gotoxy(18,11);
    _flushall();
   scanf("%c",&E->gender);
    gotoxy(18,14);
    _flushall();
  gets(E->name);
    gotoxy(50,5);
   gets(E->adress);
    gotoxy(50,8);
   scanf("%lf",&E->salary);
    gotoxy(50,11);
   scanf("%lf",&E->overtime);
   gotoxy(50,14);
   scanf("%lf",&E->deduct);

   E->pNext = E->pPre = NULL;

   return E;
   }
void AddNode(){
 Employee* pNew = NewEmp();
if(pLast == NULL)
    pLast = pStart = pNew;
else {
    pLast->pNext =pNew;
    pNew->pPre = pLast;
    pLast= pNew;
}

}



void displayAll(){
    system("cls");
 Employee *pDisplay = pStart;

    int i ,flag=0;
    while (pDisplay != NULL) {

    printf("Employee ID : %d \n",pDisplay->id);
printf("name : ");puts(pDisplay->name);
printf("NetSalary = %lf EGP \n",pDisplay->salary+pDisplay->overtime-pDisplay->deduct);
flag=1;

pDisplay = pDisplay->pNext;
    }
    if(flag==0)
        printf("no employees to show");
_getch();
}
///*************************************************///
 Employee * SearchList(int id){
 Employee * pSearch = pStart;
while(pSearch !=NULL){
    if (pSearch -> id == id)
    break;
    pSearch = pSearch ->pNext;
}
return pSearch;
};

///***************************************************/////
void displayByID(int id){

     Employee *pDisplay = SearchList(id);
    if (pDisplay == NULL)
        printf("\n not found");
        else {
            system("cls");
    int  flag =0;

printf("Employee ID : %d \n",pDisplay->id);
printf("name : ");puts(pDisplay->name);
printf("NetSalary = %lf EGP \n",pDisplay->salary+pDisplay->overtime-pDisplay->deduct);
flag = 1;
           }



_getch();

        }
///****************************************************////

void deleteByID(int id){
         Employee *pDelete = SearchList(id);


        if(pDelete == NULL)
            printf("not found");

        else{
            if  (pStart == pLast) //list has only one element
        {
            pLast = pStart = NULL;
        }
          else  if  (pDelete == pStart) //delete first element
        {
            pStart = pStart->pNext;
            pStart->pPre = NULL;
        }
        else if  (pDelete == pLast) // delete last element
        {
            pLast = pLast->pPre;
            pLast->pNext = NULL;
        }

        else
        {
            pDelete->pPre->pNext =pDelete->pNext;
            pDelete->pNext->pPre= pDelete  ->pPre;
        }


        printf("\n the employee has been deleted");
        }



_getch();
}

void deleteAll(){
    system("cls");
     Employee* pTemp;
    if (pStart == NULL)
        printf("No Employees To Delete");
    else{
        while(pStart!=NULL)
    {
        pTemp =pStart;
        pStart= pStart->pNext;
        free(pTemp);
    }
    pLast = NULL;

   printf("All Employees Have Been Deleted");
    }

_getch();
}
};

///**********************************************************///
///**********************************************************///
/*void New(){
    struct Employee* E = (struct Employee) malloc(sizeof(struct Employee));
    int ovrrd;
if (E->id!=0&&E->salary!=0){
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
*/
///************************************************************///



int main()
{
DoubleLinkedList D;

    char ch, menu[6][20] ={"New","Display By ID","Display All","Delete By ID","Delete All","Exit"};
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

    D.AddNode();
    break;
case 1: //DisplayByID
     system("cls");
    printf("please enter an ID : ");
    int id;
    scanf("%d",&id);

    D.displayByID(id);
    break;
case 2 : //displayAll
    D.displayAll();
    break;
    case 3: //DeleteById
        system("cls");
    printf("Please Enter The Id Of The Employee You Want To Delete: ");
    int ID;
    scanf("%i",&ID);


        D.deleteByID(ID);
    break;
case 4: //DeleteAll
  D.deleteAll();
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
