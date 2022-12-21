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
/**********************************************/
class colore{
int clr;
public :
    colore(){}
    colore (int c){clr=c;}
    ~colore(){}

    void setColore(int x){clr=x;}
    int getcolor(){return clr;}

};
/**********************************************/
class shape :public colore{
public:
    shape(){cout<<"shape parameterless constructor"<<endl;}
    shape(int clr):colore(clr){}

    //~shape(){cout << "shape destructor"<<endl;}
    virtual void draw() = 0;

};
/****************************************************/
class rect: public shape{
private:
    Point UL;
    Point LR;
public:
     rect(){}
    ///constructor
    rect(int Ux,int Uy,int Lx,int Ly,int c):UL(Ux,Uy),LR(Lx,Ly),shape(c){
    cout<<"rectangle constructor"<<endl;
    }
    ///destructor
    //~rect(){ cout << "rectangle destructor"<<endl;}
    void draw(){
         setcolor(getcolor());
    rectangle(UL.GetX(),UL.GetY(),LR.GetX(),LR.GetY());
    }

};

class Circ:public shape{
private:
    Point Center;
    int r;
public:
    Circ(){
        //cout<<"circle parameterless constructor"<<endl;
    }
    ///constructor
    Circ(int x,int y,int _r,int c):Center(x,y),shape(c){
    r=_r;
    cout<<"Circle constructor"<<endl;
    }
    ///destructor
   // ~Circ(){ cout << "Circle destructor"<<endl;}

    void draw(){
 setcolor(getcolor());
    circle(Center.GetX(),Center.GetY(),r);

    }

};

class Line:public shape{
private:
    Point ST;
    Point End;


public:
    Line(){}
    ///constructor
    Line(int Sx,int Sy,int Ex,int Ey,int c):ST(Sx,Sy),End(Ex,Ey),shape(c){
    //cout<<"Line constructor"<<endl;
    }
    ///destructor
    //~Line(){ cout << "Line destructor"<<endl;}

    void draw(){
         setcolor(getcolor());
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


class Tri : public shape{
Point p1;
Point p2;
Point p3;
public:
    Tri(){}
Tri(int p1d1,int p1d2,int p2d1,int p2d2,int p3d1,int p3d2, int C):p1(p1d1,p1d2),p2(p2d1,p2d2),p3(p3d1,p3d2),shape(C){}

//~Tri() {cout <<"this is Triangle destructor"<<endl;}

void draw(){
    setcolor(getcolor());
line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
line(p2.GetX(),p2.GetY(),p3.GetX(),p3.GetY());
}

};

class picture{
shape** sh;
int shSize;
public:
    picture(){}
picture(shape** _sh,int _shsize){
sh = _sh;
shSize = _shsize;
}
//~picture(){cout<<"picture destructor"<<endl;}

void draw(){

    for(int i=0;i<shSize;i++){
    sh[i]->draw();
}
}
};


int main()
{
    initgraph();

Line* L = new Line[4];
L[0]=Line(670,533,670,278,2);

L[1]=    Line(695,533,695,278,2);


L[2]=    Line(630,295,660,182,5);


   L[3]= Line(729,295,695,182,5);



rect* R =new rect[2];

R[0]=rect(670,278,695,533,2);

R[1]=rect(556,530,810,595,2);


Circ* C= new Circ[7];

    C[0]=Circ(687,435,50,9);

    C[1]=Circ(677,435,50,9);

    C[2]=Circ(677,445,50,9);

    C[3]=Circ(687,445,50,9);

    C[4]=Circ(681,440,40,9);

    C[5]=Circ(680,300,100,2);

    C[6]=Circ(677,180,50,2);



    Tri* T = new Tri[1] ;

    T[0] =Tri(620,560,645,580,595,580,5);


    shape* sh[14] = {L,&L[1],&L[2],&L[3],R,&R[1],C,&C[1],&C[2],&C[3],&C[4],&C[5],&C[6],T};

picture *p = new picture(sh,14);
p->draw();
    return 0;
}
