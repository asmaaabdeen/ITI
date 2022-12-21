#include "C:\Program Files\CodeBlocks\MinGW\include\graphics.h"
#include <iostream>
#include<conio.h>
using namespace std;

class Point {
private:
   int x;
   int y;

public:

    Point(){
    x=y=0;
    //cout<< "point parameterless constructor "<<endl;
    }

    Point(int _x, int _y){
    x=_x;
    y=_y;
    //cout<< "point parameterized constructor "<<endl;
    }

    ~Point(){
    //cout<< "point destructor "<<endl;
    }

    int GetX(){return x;}
    int GetY(){return y;}

    void SetX(int _x){x=_x;}
    void SetY(int _y){y=_y;}

    void show(){ cout<<"("<<x<<","<<y<<")"<<endl; }
};

class rect{
private:
    Point UL;
    Point LR;
    int Clr;
public:
    ///constructor
    rect(int Ux,int Uy,int Lx,int Ly,int c):UL(Ux,Uy),LR(Lx,Ly){
    Clr=c;
    cout<<"rectangle constructor"<<endl;
    }
    ///destructor
    ~rect(){ cout << "rectangle destructor"<<endl;
    }

    void draw(){
         setcolor(Clr);
    rectangle(UL.GetX(),UL.GetY(),LR.GetX(),LR.GetY());
    }

};

class Circ{
private:
    Point Center;
    int r;

    int Clr;
public:
    ///constructor
    Circ(int x,int y,int _r,int c):Center(x,y){
    Clr=c;
    r=_r;
    cout<<"Circle constructor"<<endl;
    }
    ///destructor
    ~Circ(){ cout << "Circle destructor"<<endl;
    }

    void draw(){
 setcolor(Clr);
    circle(Center.GetX(),Center.GetY(),r);

    }

};

class Line{
private:
    Point ST;
    Point End;

    int Clr;
public:
    ///constructor
    Line(int Sx,int Sy,int Ex,int Ey,int c):ST(Sx,Sy),End(Ex,Ey){
    Clr=c;
    //cout<<"Line constructor"<<endl;
    }
    ///destructor
    ~Line(){ cout << "Line destructor"<<endl;
    }

    void draw(){
         setcolor(Clr);
    line(ST.GetX(),ST.GetY(),End.GetX(),End.GetY());
    }

};

/*class Elips{
private:
    Point Strt;
    Point Rad;
    int start_angle;
    int end_angle;

    int Clr;
public:
    ///constructor
    Elips(int Sx,int Sy,int rx,int ry,int Sa , int ea ,int c):Strt(Sx,Sy),Rad(rx,ry){
    Clr=c;
    start_angle = Sa;
    end_angle = ea;
    //cout<<"rectangle constructor"<<endl;
    }
    ///destructor
    ~Elips(){ //cout << "Circle destructor"<<endl;
    }

    void draw(){
    ellipse(Strt.GetX(),Strt.GetY(),start_angle,end_angle,Rad.GetX(),Rad.GetY());
    }

};*/






int main()
{
    initgraph();

    /*Point P1;
    P1.SetX(5);P1.SetY(10);
    P1.show();
    cout<<P1.GetY()<<endl;*/




    Line L1(670,533,670,278,2);
    L1.draw();

    Line L2(695,533,695,278,2);
    L2.draw();

    Line L3(630,295,660,182,5);
    L3.draw();

    Line L4(729,295,695,182,5);
    L4.draw();


rect R2(670,278,695,533,2);
    R2.draw();
rect R1(556,530,810,595,2);
    R1.draw();



    Circ C2(687,435,50,9);
    C2.draw();

    Circ C3(677,435,50,9);
    C3.draw();

    Circ C5(677,445,50,9);
    C5.draw();

    Circ C4(687,445,50,9);
    C4.draw();




    Circ C1(681,440,40,9);
    C1.draw();



    Circ C6(680,300,100,2);
    C6.draw();


    Circ C7(677,180,50,2);
    C7.draw();


    Line t1(620,560,645,580,5);
    t1.draw();

    Line t2(620,560,595,580,5);
    t2.draw();

    Line t3(595,580,645,580,5);
    t3.draw();

    return 0;
}
