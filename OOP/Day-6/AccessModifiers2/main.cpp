#include <iostream>

using namespace std;

///***public - private***///
/*class parent {

int a;
protected: int b;
public :int c;
parent(){}

parent (int x,int y ,int z){
a=x; //yes
b=y; //yes
c=z; //yes
}

int fun (){
return
a+ //yes
b+ //yes
c; //yes
}
};

class fchild:public parent
 {

int d;
protected: int e;
public :int f;

fchild(){}
fchild (int x,int y ,int z,int k,int l,int m):parent(k,l,m){
d=x; //yes
e=y; //yes
f=z; //yes
}

int fun (){
return
   d+ //yes
   e+ //yes
   f+ //yes
///a+   no because it is private in the parent (parent) class
   b+ //yes
   c; //yes
}
};

class Schild:private fchild
 {

int g;
protected: int h;
public :int i;

Schild(){}
Schild (int x,int y ,int z,int k,int l,int m,int n,int o,int p):fchild(k,l,m,n,o,p){
g=x;  //yes
h=y; //yes
i=z;//yes
}

int fun (){
return
   g+ //yes
   h+ //yes
   i+ //yes
///d+ no because it is private in the parent (parent) class
   e+ //yes
   f+ //yes
///a+ no because it is private in the parent (fchild) class
   b+ //yes
   c; //yes
}
};*/

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

///**protected-public**///
/*
class parent {

int a;
protected: int b;
public :int c;
parent(){}

parent (int x,int y ,int z){
a=x; //yes
b=y; //yes
c=z; //yes
}

int fun (){
return
a+ //yes
b+ //yes
c; //yes
}
};

class fchild:protected parent
 {

int d;
protected: int e;
public :int f;

fchild(){}
fchild (int x,int y ,int z,int k,int l,int m):parent(k,l,m){
d=x; //yes
e=y; //yes
f=z; //yes
}

int fun (){
return
   d+ //yes
   e+ //yes
   f+ //yes
///a+   no because it is private in the parent (parent) class
   b+ //yes
   c; //yes
}
};

class Schild:public fchild
 {

int g;
protected: int h;
public :int i;

Schild(){}
Schild (int x,int y ,int z,int k,int l,int m,int n,int o,int p):fchild(k,l,m,n,o,p){
g=x;  //yes
h=y; //yes
i=z;//yes
}

int fun (){
return
   g+ //yes
   h+ //yes
   i+ //yes
///d+ no because it is private in the parent (parent) class
   e+ //yes
   f+ //yes
///a+ no because it is private in the parent (fchild) class
   b+ //yes
   c; //yes
}
};
*/

/*******************************************************************************************/
/*******************************************************************************************/
/*******************************************************************************************/

///public-protected**///

class parent {

int a;
protected: int b;
public :int c;
parent(){}

parent (int x,int y ,int z){
a=x; //yes
b=y; //yes
c=z; //yes
}

int fun (){
return
a+ //yes
b+ //yes
c; //yes
}
};

class fchild:public parent
 {

int d;
protected: int e;
public :int f;

fchild(){}
fchild (int x,int y ,int z,int k,int l,int m):parent(k,l,m){
d=x; //yes
e=y; //yes
f=z; //yes
}

int fun (){
return
   d+ //yes
   e+ //yes
   f+ //yes
///a+   no because it is private in the parent (parent) class
   b+ //yes
   c; //yes
}
};

class Schild:protected fchild
 {

int g;
protected: int h;
public :int i;

Schild(){}
Schild (int x,int y ,int z,int k,int l,int m,int n,int o,int p):fchild(k,l,m,n,o,p){
g=x;  //yes
h=y; //yes
i=z;//yes
}

int fun (){
return
   g+ //yes
   h+ //yes
   i+ //yes
///d+   no because it is private in the parent (fchild) class
   e+ //yes
   f+ //yes
///a+ //no because it is private in the parent (fchild) class
   b+ //yes because it's protected
   c; //yes because it's public
;}
};

int main()
{
    ///**public - private**///
/*
    parent p;
///    p.a;    no because it is private in the parent (parent) class
///    p.b;    no because it is protected in the parent (parent) class
       p.c;    //yes

    fchild c1;
//    c1.a; ///no///
//    c1.b; ///no///
    c1.c; //yes
//    c1.d; ///no///
//    ci.e; ///no///
    c1.f; //yes

    Schild c2;
//    c2.a; ///no///
//    c2.b; ///no///
///    c2.c; // no because it is private in the parent (fchild) class
//    c2.d; ///no///
//    c2.e; ///no///
///    c2.f; // no because it is private in the parent (fchild) class
//    c2.g; ///no///
//    c2.h; ///no///
    c2.i; // yes
*/

    ///**protected-public**///
/*
    parent p;
///    p.a;    no because it is private in the parent (parent) class
///    p.b;    no because it is protected in the parent (parent) class
       p.c;    //yes

    fchild c1;
//    c1.a; ///no///
//    c1.b; ///no///
///    c1.c; no because it's protected
//    c1.d; ///no///
//    ci.e; ///no///
    c1.f; //yes

    Schild c2;
//    c2.a; ///no///
//    c2.b; ///no///
///    c2.c; no because it's protected
//    c2.d; ///no///
//    c2.e; ///no///
      c2.f; //yes
//    c2.g; ///no///
//    c2.h; ///no///
    c2.i; //yes

*/
    ///**public-protected**///

    parent p;
///    p.a;    no because it is private in the parent (parent) class
///    p.b;    no because it is protected in the parent (parent) class
       p.c;    //yes

    fchild c1;
///    c1.a; ///no///
///    c1.b; ///no///
      c1.c; //yes cause it is inherited as public
///    c1.d; ///no///
///    ci.e; ///no///
      c1.f; //yes

    Schild c2;
//    c2.a; ///no///
//    c2.b; ///no///
///    c2.c; ///no because it's inherited as protected
//    c2.d; ///no///
//    c2.e; ///no///
///    c2.f; ///no because it's inherited as protected
//    c2.g; ///no///
//    c2.h; ///no///
    c2.i; //yes

    return 0;
}
