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
class rect: private colore{
private:
    Point UL;
    Point LR;
public:
     rect(){}
    ///constructor
    rect(int Ux,int Uy,int Lx,int Ly,int c):UL(Ux,Uy),LR(Lx,Ly),colore(c){
    cout<<"rectangle constructor"<<endl;
    }
    ///destructor
    ~rect(){ cout << "rectangle destructor"<<endl;
    }
    void draw(){
         setcolor(getcolor());
    rectangle(UL.GetX(),UL.GetY(),LR.GetX(),LR.GetY());
    }

};

class Circ:private colore{
private:
    Point Center;
    int r;
public:
    Circ(){cout<<"circle parameterless constructor"<<endl;}
    ///constructor
    Circ(int x,int y,int _r,int c):Center(x,y),colore(c){
    r=_r;
    cout<<"Circle constructor"<<endl;
    }
    ///destructor
    ~Circ(){ cout << "Circle destructor"<<endl;
    }

    void draw(){
 setcolor(getcolor());
    circle(Center.GetX(),Center.GetY(),r);

    }

};

class Line:private colore{
private:
    Point ST;
    Point End;


public:
    Line(){}
    ///constructor
    Line(int Sx,int Sy,int Ex,int Ey,int c):ST(Sx,Sy),End(Ex,Ey),colore(c){
    //cout<<"Line constructor"<<endl;
    }
    ///destructor
    ~Line(){ cout << "Line destructor"<<endl;
    }

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


class Tri : public colore{
Point p1;
Point p2;
Point p3;
public:
    Tri(){}
Tri(int p1d1,int p1d2,int p2d1,int p2d2,int p3d1,int p3d2, int C):p1(p1d1,p1d2),p2(p2d1,p2d2),p3(p3d1,p3d2),colore(C){}

~Tri() {cout <<"this is Triangle destructor"<<endl;}

void draw(){
    setcolor(getcolor());
line(p1.GetX(),p1.GetY(),p2.GetX(),p2.GetY());
line(p1.GetX(),p1.GetY(),p3.GetX(),p3.GetY());
line(p2.GetX(),p2.GetY(),p3.GetX(),p3.GetY());
}

};

class picture{
rect* r;
Circ* c;
Tri* t;
Line* l;
int Rsize,Csize,Tsize,Lsize;
public:
picture(rect* _r,Circ* _c,Tri* _t,Line* _l,int rsize,int csize,int tsize,int lsize){
r = _r;
c = _c;
t = _t;
l = _l;
Rsize =rsize;
Csize =csize;
Tsize =tsize;
Lsize =lsize;
}
~picture(){cout<<"picture destructor"<<endl;}

void draw(){

    for(int i=0;i<Lsize;i++){
    l[i].draw();
}
for(int i=0;i<Rsize;i++){
    r[i].draw();
}
for(int i=0;i<Tsize;i++){
    t[i].draw();
}
for(int i=0;i<Csize;i++){
    c[i].draw();
}


}
};


int main()
{
    initgraph();

Line* L = new Line[4]{
Line(670,533,670,278,2),

    Line(695,533,695,278,2),


    Line(630,295,660,182,5),


    Line(729,295,695,182,5)


};

rect* R =new rect[2]{

rect(670,278,695,533,2),

rect(556,530,810,595,2)
};


Circ* C= new Circ[7]{

    Circ(687,435,50,9),

    Circ(677,435,50,9),

    Circ(677,445,50,9),

    Circ(687,445,50,9),

    Circ(681,440,40,9),

    Circ(680,300,100,2),

    Circ(677,180,50,2)};



    Tri* T = new Tri[1] {Tri(620,560,645,580,595,580,5)};


    picture p(R,C,T,L,2,7,1,4);

    p.draw();
    return 0;
}
