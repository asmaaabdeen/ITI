#include <iostream>

using namespace std;
class MyQueue{

int *Que;
    int tail, Size, length;

public:
    //parameterized constructor
    MyQueue(int S){

        tail=0;
        length=0;
    Size = S;
    Que = new int(Size);

    for (int i=0;i<Size;i++){
        Que[i]=0;
    }
    }
    //parameterless constructor
    MyQueue(){

        tail=0;
        length=0;
    Size = 7;
    Que = new int(7);

    for (int i=0;i<7;i++){
        Que[i]=0;
    }
    }
    //destructor
    ~MyQueue(){
        delete []Que;
    }

    bool IsFull(){

        return length==Size ;
    }

    bool IsEmpty(){
        return length==0 ;
    }

    int DeQ(){
        if (!IsEmpty())
        {
            int x;
            x=Que[tail];
            Que[tail]=Que[tail+1];
            length --;

             return x;
        }

        else {cout<<"can't deque .. Queue is empty"<<endl;
        return -1;}
    }

    int peek (){
    if (!IsEmpty())
        return Que[tail];
        else {cout<<"Queue is empty"<<endl;
        return -1;}
    }

    void EnQ(int y){
        if(!IsFull())
        {
              Que[tail]=y;
              tail++;
              length++;
              if(tail==Size)
                tail=0;
        }

        else cout<<"can't Enque .. Queue is full"<<endl;

    }
int QueueCount(){
if (!IsEmpty())
        return tail;
else {cout<<"Queue is empty"<<endl;
        return -1;}
}
void printQ(){
for(int i =0;i<Size;i++){
    cout<<"element "<< i+1 <<" = " << Que[i]<<endl;
}
}
};
int main()
{
    int Size;
    cout <<"please enter the size of Queue ";
    cin>> Size;
    MyQueue Q(Size);

    Q.EnQ(10);Q.EnQ(7);Q.EnQ(9);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    cout<< "first element of Q is "<<Q.peek()<<endl;
    cout <<"DeQued "<< Q.DeQ()<<endl;

    Q.EnQ(1);Q.EnQ(2);Q.EnQ(3);Q.EnQ(4);Q.EnQ(5);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    cout <<"DeQued "<< Q.DeQ()<<endl;cout <<"DeQued "<< Q.DeQ()<<endl;
    Q.EnQ(100);Q.EnQ(120);
    cout <<endl;
    Q.printQ();
    cout <<"DeQued "<< Q.DeQ()<<endl;
    Q.EnQ(60);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    return 0;
}
