#include <iostream>

using namespace std;
class MyQueue{

int *Que;
    int head, tail, Size, length;

public:
    //parameterized constructor
    MyQueue(int S){
        head=0;
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
        head=0;
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

    bool IsFull(){return length==Size ;}
    bool IsEmpty(){return length==0 ;}

    int DeQ(){
        if (!IsEmpty())
        {
            int x;
            x=Que[head];

            head = (head+1)%Size;
              length --;
             return x;
        }

        else {cout<<"can't deque .. Queue is empty"<<endl;
        return -1;}
    }

    int peek (){
    if (!IsEmpty())
        return Que[head];
        else cout<<"Queue is empty"<<endl;
        return -1;
    }

    void EnQ(int y){
        if(!IsFull())
        {
              Que[tail]=y;
              tail = (tail+1)%Size;
              length++;
        }

        else cout<<"can't Enque .. Queue is full"<<endl;

    }

int QueueCount(){
if (!IsEmpty())
        return head;
else {cout<<"Queue is empty"<<endl;
        return -1;}
}

void printQ(){
for(int i=Size-1 ; i>=0 ; i--){
    cout<<"element "<< i+1 <<" = " << Que[i]<<endl<<endl;
}
}
};
int main()
{
    int Size;
    cout <<"please enter the size of Queue ";
    cin>> Size;
    MyQueue Q(Size);

    Q.EnQ(10);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    Q.EnQ(7);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    Q.EnQ(9);Q.EnQ(8);Q.EnQ(7);
    cout<< "elements of Q "<< endl ;
    Q.printQ();


    //cout<< "first element of Q is "<<Q.peek()<<endl;
    cout <<"DeQued "<< Q.DeQ()<<endl;

    Q.EnQ(1);
    cout<< "elements of Q "<< endl ;
    Q.printQ();

    cout <<"DeQued "<< Q.DeQ()<<endl;

    //cout <<"DeQued "<< Q.DeQ()<<endl;
    Q.EnQ(100);
   cout<< "elements of Q "<< endl ;
    Q.printQ();
    /*cout <<"DeQued "<< Q.DeQ()<<endl;
    Q.EnQ(60);*/

    Q.EnQ(20);Q.EnQ(30);Q.EnQ(40);
    cout<< "elements of Q "<< endl ;
    Q.printQ();
    return 0;
}
