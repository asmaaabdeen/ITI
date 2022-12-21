#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#define NormalPen 0x0b
#define HighlightPen 0xb0
#define Enter 0x0d
#define Esc  27

 //char line[100];

void gotoxy (int column, int line){
COORD coord;
coord.X = column;
coord.Y = line;
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/***********************************************************************************/

char** MultiLineEditor(int c ,int *size ,int *row,int *col,int *Strtch,int *Endch){
char ch ,*current,*start,*end;

char **line; int i;
line = (char**) malloc(c*sizeof(char*));
for(i=0;i<c;i++){
line[i] = (char*) malloc((size[i]+1)*sizeof(char));
}

int ExitFlag =0 , ExitFlag2 =0,index=0,j,k,h,endrow , currentRow ;



for(i=0;i<c;i++){
for(j=0;j<size[i];j++){
    gotoxy(row[i]+j,col[i]);
    textattr(90);
    printf(" ");
}}


for(i=0;i<c;i++){
current = start = end = line[i];
endrow = row[i];
currentRow = row[i];

j=0;
  do{
gotoxy(row[i],col[i]);
    ch = getch();
    ExitFlag = 0;
    ExitFlag2 = 0;


switch (ch){
     case 9: //tap
        *end = '\0';
        ExitFlag =1;
    break;
    case Enter :
        *end = '\0';
        ExitFlag =1;
        ExitFlag2 =1;

    break;
case Esc:
        *end = '\0';
        ExitFlag =1;
        ExitFlag2 =1;
    break;
   case -32:
    ch = getch();
    switch(ch){
case 75: //left

    if(current >start)
       {
           current --;
           currentRow--;
    gotoxy(row[i]--,col[i]);
       }
    break;
case 77: //right

    if(current < end)
       {

        current ++;    /// increase address of line array
        currentRow++;
        gotoxy(row[i]++,col[i]);
       }

    break;
case 71: //home
    current = line;
    gotoxy(row,col);
    break;
case 97: //end2
     current = end;
      gotoxy(endrow,col);
    break;
    case 72: //up
     i--;
    break;
     case 80: //down
    *end = '\0';
    ExitFlag =1;
    break;
    }
break;

    default:
        if(ch<=Endch[i] && ch>=Strtch[i]){
            //printf("s=%i j=%i c=%i" , row[i] , j , currentRow );
            if( (currentRow < row[i] + size[i]) && j<size[i] ){
                printf("%c",ch);
                *current = ch;
                current++;
                end++;
                currentRow++;
                endrow++;
                gotoxy(row[i]++,col[i]);
                if(j < size[i]){
                    j++;
                }

            }

}

}

}while(!ExitFlag);
    if(ExitFlag2){i=c;}

}


return line;

}
/*************************************************************************************/

void textattr (int i){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}
///////////////////////////////////////////////////////////////////////////////////////////
struct Employee {
    int id,age;
    char gender,name[100],adress[200];
    double salary,overtime,deduct;
};

///////////////////////////////////////////////////////////////////////////////////////////

void New(int idx ,struct Employee *E,int Eno){
    int ovrrd;
if (E[idx].id!=-1){
     printf("the index is already  allocated do you want to override the old data or exit ? press 0 to exit or 1 to override ");

     scanf("%d",&ovrrd);
           if (ovrrd==0){
               _getch();
           }
else if (ovrrd==1)
form(idx,E);
}
else form(idx,E);
}
void form(int idx,struct Employee *E){

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
int *size,*row,*col,*strtch,*endch;
size = (int*) malloc(8*sizeof(int));
size[0]=3;size[1]=2;size[2]=1;size[3]=10;size[4]=10;size[5]=5;size[6]=4;size[7]=4;

row = (int*) malloc(8*sizeof(int));
row[0]=18;row[1]=18;row[2]=18;row[3]=18;row[4]=50;row[5]=50;row[6]=50;row[7]=50;

col = (int*) malloc(8*sizeof(int));
col[0]=5;col[1]=8;col[2]=11;col[3]=14;col[4]=5;col[5]=8;col[6]=11;col[7]=14;

strtch = (int*) malloc(8*sizeof(int));
strtch[0]=48;strtch[1]=48;strtch[2]=65;strtch[3]=65;strtch[4]=65;strtch[5]=48;strtch[6]=48;strtch[7]=48;

endch = (int*) malloc(8*sizeof(int));
endch[0]=57;endch[1]=57;endch[2]=122;endch[3]=122;endch[4]=122;endch[5]=57;endch[6]=57;endch[7]=57;

int a;
char **data;

data = (char**) malloc(8*sizeof(char*));
for(a=0;a<8;a++){
data[a] = (char*) malloc((size[a]+1)*sizeof(char));
}
data = MultiLineEditor(8,size,row,col,strtch,endch);

   E[idx].id =atoi( data[0]);//id
 E[idx].age = atoi( data[1]);//age
 E[idx].gender = data[2];//gender
  strcpy(E[idx].name , data[3]);//name
  strcpy(E[idx].adress , data[4]);//address
   E[idx].salary = atoi( data[5]);//salary
   E[idx].overtime = atoi(  data[6]);//overtime
     E[idx].deduct =  atoi( data[7]);//deduct

   }

/**************************************************************/

void displayAll(struct Employee *E,int Eno){
    system("cls");

    int i ,flag=0;
    for (i=0;i<Eno;i++){
if(E[i].id!=-1){
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

//////////////////////////////////////////////////////////////////////////////////////////

void displayByID(int id,struct Employee *E,int Eno){
    system("cls");
    int i, flag =0;
    for (i=0;i<Eno;i++){
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

////////////////////////////////////////////////////////////////////////////////////////////

void deleteByID(int id,struct Employee *E,int Eno){
 int i,flag =0;;
    for (i=0;i<Eno;i++){
        if(id==E[i].id){
E[i].id=-1;
flag = 1;
printf("the employee has been deleted");
           }

    }
     if (flag ==0)
        printf("this id does not exist");
_getch();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void deleteByName(struct Employee *E,int Eno){
    system("cls");
    printf("please enter the name of the employee you want to delete : ");
    char Name[100];
    _flushall();
    gets(Name);
 int i,flag =0;;
    for (i=0;i<Eno;i++){
        if(strcmp(Name,E[i].name)==0){
E[i].id=-1;
flag = 1;
printf("the employee has been deleted");
           }

    }
     if (flag ==0)
        printf("this Name does not exist");
_getch();
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
struct Employee *E;
int ENo,h ;
textattr(90);
printf("enter the number of employees : ");
scanf("%i",&ENo);
E= (struct Employee*) malloc((ENo)*sizeof(struct Employee));
for(h=0;h<ENo;h++){
E[h].id = -1;
}

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
    printf("Please Enter The Index You Want To Add New Employee In (it must be from 0to%i) : ",(ENo)-1);
    int indx;
    scanf("%i",&indx);
    printf("\n");
    New(indx,E,ENo);
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
    displayByID(id,E,ENo);
    break;
case 2 : //displayAll
    displayAll(E,ENo);
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
        deleteByID(ID,E,ENo);
    break;
case 4: //DeleteByName
  deleteByName(E,ENo);
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
/*int i;
for(i=0;i<20;i++){

    gotoxy(i,2);
printf(" ");
    textattr(30);

}
*/
    return 0;
}
