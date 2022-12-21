#include <iostream>

using namespace std;
class MyStack {
int *stk ,tos,Size;

public:

MyStack (const MyStack &oldS){
tos = oldS.tos;
Size = oldS.Size;
stk = new int(Size);
for(int i = 0 ; i<tos;i++){
    stk[i] = oldS.stk[i];
}
}
/*************************************************/

    MyStack(int S=8){
        tos=0;
    Size = S;
    stk = new int(Size);
    }
    ~MyStack(){
        for(int i =0;i<tos;i++){
            stk[i]=-1;
        }
        delete []stk;
    }

/*************************************************/

    bool IsFull(){return (tos==Size) ;}
    bool IsEmpty(){return (tos==0) ;}

/*************************************************/

    int pop(){
        if (!IsEmpty())
       return stk[--tos];
        else cout<<"can't pop .. stack is empty"<<endl;
        return -1;
    }

/*************************************************/

    int peek (){
    if (!IsEmpty())
        return stk[tos-1];
        else cout<<"stack is empty"<<endl;
        return -1;
    }

/*************************************************/

    void push(int y){
        if(!IsFull())
            stk[tos++]=y;
        else cout<<"can't push .. stack is full"<<endl;

    }

/*************************************************/

int StackCount(){
if (!IsEmpty())
        return tos;
else cout<<"stack is empty"<<endl;
        return -1;
}

/*************************************************/

MyStack Reverse(){
MyStack R(7);
int x = tos;
for(int i = 0 ; i < tos+i ; i++){

    R.push(peek());
    tos--;
}
tos =x;
return R;
}

MyStack operator+ (MyStack S){
MyStack New(tos+(S.tos)) ;
int x = tos ,y=S.tos;


for (int i =tos;i<New.Size;i++){
    New.push(S.pop());
}
for (int i =0;i<tos+i;i++){
    New.push(pop());
}
tos = x;
S.tos=y;
return New;
}

/*************************************************/

MyStack& operator= (const MyStack& S){
delete []stk;
tos = S.tos;
Size = S.Size;
stk = new int(Size);
for(int i = 0 ; i<tos;i++){
    stk[i] = S.stk[i];
}
return *this ;
}
/****************************************/

int operator[](int index){
    if((index>=0)&&(index<tos))
        return stk[index];
    else {cout << "invalid index"<<endl;
    return -1;}
    }

friend void ViewContent(MyStack S);
};
 void ViewContent(MyStack S){
    if(S.IsEmpty())
        cout<<"the stack is empty"<<endl;
    else
for(int i=0;i<S.tos;i++)
    cout<<S.stk[i]<<endl;
}
int main()
{

    MyStack S1(7);
    S1.push(5);
    S1.push(6);
    S1.push(7);
    ViewContent(S1);
    cout<<"********************"<<endl;
     MyStack S2(7);
    S2.push(15);
    S2.push(16);
    S2.push(17);
    ViewContent(S2);
    cout<<"********************"<<endl;
    MyStack S3(7);
    S3=S1+S2;
    ViewContent(S3);
      cout<<"********************"<<endl;
      ViewContent(S1);
          cout<<"********************"<<endl;

          cout << S1[0] <<endl;
           cout << S1[1] <<endl;
     /*cout<< S3.pop()<<endl;
      cout<<"********************"<<endl;
      ViewContent(S3);
       cout<<"********************"<<endl;
     cout<< S3.pop()<<endl;
      cout<<"********************"<<endl;
      ViewContent(S3);*/

    /*cout<<S1.peek()<<endl;
    S1.push(8);
    cout << S1.peek()<<endl;
    cout << S1.pop()<<endl;
    cout << S1.peek()<<endl;
    S1.push(11);
   cout<<S1.peek()<<endl;
    S1.push(15);
    cout << S1.peek()<<endl;
    cout << S1.pop()<<endl;
     cout <<"count of elements is "<< S1.StackCount()<<endl;
S1.push(200);
  cout << S1.peek()<<endl;
   cout <<"count of elements is "<< S1.StackCount()<<endl;
   ViewContent(S1);
   cout << "**************************"<<endl;
cout << S1.pop()<<endl;
cout << "**************************"<<endl;
ViewContent(S1);
cout << "**************************"<<endl;
   MyStack S2(7);
   ViewContent(S2);
   S2 = S1.Reverse();
   ViewContent(S2);
   cout << "**************************"<<endl;
    ViewContent(S1);
     cout << "**************************"<<endl;
     cout << S1.pop()<<endl;
    cout<<S1.Reverse().pop();*/



    return 0;
}
