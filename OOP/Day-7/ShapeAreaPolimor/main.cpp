#include <iostream>
using namespace std;

///shape class*************
class shape{
    protected:
int d1;
int d2;
public:
    shape(){
    cout<<"parameterless constructor of shape"<<endl;
    }
shape(int _d1,int _d2)
    {d1=_d1;
    d2=_d2;}
~shape(){cout<<"shape destructor"<<endl;}

int getd1(){return d1;}
int getd2(){return d2;}

void setd1(int d){d1=d;}
void setd2(int d){d2=d;}
virtual double CalcArea(){
return d1*d2;
}
};

///rectangle class inherits shape ********

class rect: public shape{
public:
     rect(){
    cout<<"parameterless constructor of rect"<<endl;
    }
rect(int d1,int d2):shape(d1,d2){}
~rect(){cout<<"rectangle destructor"<<endl;}

};
///class square inherit rectngle
class sqr: public rect{
public:
    sqr(){
    cout<<"parameterless constructor of square"<<endl;
    }
sqr(int d):rect(d,d){}
~sqr(){cout<<"squre destructor"<<endl;}

/**overriding setd1 & d2 so no one can set the hight of sqr different from width**/
void setd1(int _d){
    d1=d2=_d;}
void setd2(int _d){d1=d2=_d;}

};
/********************************************************/
class Circ: public shape{
public:

    Circ(){
    cout<<"parameterless constructor of Circle"<<endl;
    }
Circ(int r):shape(r,r){}
~Circ(){cout<<"circle destructor"<<endl;}

void setd1(int r){d1=d2=r;}
void setd2(int r){d1=d2=r;}
void setrad(int r){d1=d2=r;}

double CalcArea(){
return d1*d2*3.14;
}
};

class Tri: public shape{
public:
     Tri(){
    cout<<"parameterless constructor of Triangle"<<endl;
    }
Tri(int b,int h):shape(b,h){}
~Tri(){cout<<"Triangle destructor"<<endl;}

double CalcArea(){
return (0.5*d1*d2);
}
};

double sumareas(shape** Shptr,int ShSize){

    double ShAreas=0;
    for (int i =0;i<ShSize;i++){
        ShAreas += Shptr[i]->CalcArea();
    }
  //cout<<Sum<<endl;
return ShAreas;
}

int main()
{


    Circ* C = new Circ[3];
    C[0].setd1(3);
    C[1].setd1(5);
    C[2].setrad(7);

    sqr* S = new sqr[2];
    S[0].setd1(4);
    S[1].setd1(5);



    Tri* T= new Tri[3];
    T[0].setd1(3); T[0].setd2(6);
    T[1].setd1(2); T[1].setd2(5);
    T[2].setd1(10); T[2].setd2(7);

    rect* R = new rect[2];
    R[0].setd1(5); R[0].setd2(10);
    R[1].setd1(3); R[1].setd2(6);



shape *ptr ;
ptr = new Circ(10);
cout <<"circle area = "<< ptr->CalcArea()<<endl;

sqr s1(5);
ptr = &s1;
cout <<"square area = "<< ptr->CalcArea()<<endl;

shape* shapeptr[10]  = {C,&C[1],&C[2],S,&S[1],T,&T[1],&T[2],R,&R[1]};
cout <<"the sum of areas of all shapes are = "<< sumareas(shapeptr,10)<<endl;
    return 0;
}
