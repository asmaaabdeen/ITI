#include <iostream>

using namespace std;
class MyStack {
int *stk ,tos,Size;

public:
    MyStack(int S){
        tos=0;
    Size = S;
    stk = new int(Size);
    }
    ~MyStack(){
        delete []stk;
    }

    bool IsFull(){

        return (tos==Size) ;
    }
    bool IsEmpty(){
        return (tos==0) ;
    }
    int pop(){
        if (!IsEmpty())
       return stk[--tos];
        else cout<<"can't pop .. stack is empty"<<endl;
        return -1;
    }
    int peek (){
    if (!IsEmpty())
        return stk[tos-1];
        else cout<<"stack is empty"<<endl;
        return -1;
    }
    void push(int y){
        if(!IsFull())
            stk[tos++]=y;
        else cout<<"can't push .. stack is full"<<endl;

    }
int StackCount(){
if (!IsEmpty())
        return tos;
else cout<<"stack is empty"<<endl;
        return -1;
}
};
int main()
{

    MyStack S1(7);
    S1.push(5);
    S1.push(6);
    cout<<S1.peek()<<endl;
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
    return 0;
}
