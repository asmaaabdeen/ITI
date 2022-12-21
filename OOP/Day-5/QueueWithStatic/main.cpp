#include <iostream>

using namespace std;
template <class t>
class MyQueue{

t *Que;
    int head, tail, Size, length;

public:
    //parameterized constructor
    MyQueue(int S){
        head=0;
        tail=0;
        length=0;
    Size = S;
    Que = new t(Size);

    /*for (int i=0;i<Size;i++){
        Que[i]=0;
    }*/
    }
    //parameterless constructor
    MyQueue(){
        head=0;
        tail=0;
        length=0;
    Size = 7;
    Que = new t(7);

   /* for (int i=0;i<7;i++){
        Que[i]=0;
    }*/
    }
    //destructor
    ~MyQueue(){
        delete []Que;
    }

    bool IsFull(){return length==Size ;}
    bool IsEmpty(){return length==0 ;}

    t DeQ(){
        if (!IsEmpty())
        {
            t x;
            x=Que[head];

            head = (head+1)%Size;
              length --;
             return x;
        }

        else {cout<<"can't deque .. Queue is empty"<<endl;
        return -1;}
    }

    t peek (){
    if (!IsEmpty())
        return Que[head];
        else cout<<"Queue is empty"<<endl;
        return -1;
    }

    void EnQ(t y){
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
    MyQueue<int> Q(Size);

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

     int S;
    cout <<"please enter the size of the second Queue ";
    cin>> S;
    MyQueue<char> cQ(S);

    cQ.EnQ('a');
    cout<< "elements of Q "<< endl ;
    cQ.printQ();
    cQ.EnQ('s');
    cout<< "elements of Q "<< endl ;
    cQ.printQ();
    cQ.EnQ('m');cQ.EnQ('a');cQ.EnQ('a');
    cout<< "elements of Q "<< endl ;
    cQ.printQ();


    //cout<< "first element of Q is "<<Q.peek()<<endl;
    cout <<"DeQued "<< cQ.DeQ()<<endl;

    cQ.EnQ('t');
    cout<< "elements of Q "<< endl ;
    cQ.printQ();

    cout <<"DeQued "<< cQ.DeQ()<<endl;

    //cout <<"DeQued "<< Q.DeQ()<<endl;
    cQ.EnQ('r');
   cout<< "elements of Q "<< endl ;
    cQ.printQ();
    /*cout <<"DeQued "<< Q.DeQ()<<endl;
    Q.EnQ(60);*/

    cQ.EnQ('s');cQ.EnQ('p');cQ.EnQ('w');
    cout<< "elements of Q "<< endl ;
    cQ.printQ();
    return 0;
}
