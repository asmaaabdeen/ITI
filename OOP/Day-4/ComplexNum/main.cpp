#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

class Complex
{
int real;
int imagin;
public:

    Complex(){
    real=6;imagin=9;
    //cout<<"parameterless constructor of "<<this->real<<endl;
    }

    Complex(int x){
    real=x;imagin=x;
    cout<<"parameterize constructor of "<<this->real<<endl;
    }

    Complex(int x,int y){
    real=x;imagin=y;
        //cout<<"parameterize constructor of "<<this->real<<endl;
    }

   Complex (Complex &oldC){
    real = oldC.real;
    imagin = oldC.imagin;

    }

void SetReal(int R){
real = R;
}
void SetImag(int I){
imagin = I;
}
int GetReal(){
return real;
}
int GetImag(){
return imagin;
}
void Print(){
    if(((real>0||real<0||real==0) && imagin ==0))
    cout << real <<endl;
else if (real ==0 && (imagin >0||imagin<0))
    cout << imagin << "i"<<endl;
else if ((real>0||real<0) && imagin<0)
    cout << real << imagin << "i"<<endl;
else cout << real << " + " << imagin << "i"<<endl;
}

Complex Sum(Complex C){
Complex result;
result.real = real + C.real;
result.imagin = imagin + C.imagin;
return result;
}

Complex operator- (const Complex& C){
Complex result;
result.real = real - C.real;
return result;
}
/*Complex Sum(Complex& C){
Complex result;
result.real = real + C.real;
result.imagin = imagin + C.imagin;
return result;
}*/

Complex operator --(){
real--;
return *this;
}
Complex operator --(int){
    Complex C(real,imagin);
real--;
return C;
}

~Complex(){
 //   cout<< "destructor of obj " << this->real << endl;
    }

Complex operator -(int L){
Complex result ;
result.real=real -L  ;
return result ;
}

Complex& operator -=(Complex& R){
real -= R.real ;
return *this ;
}

Complex& operator -=(int R){
real -= R ;
return *this ;
}

bool operator ==(Complex& R){
return (real == R.real);
}

bool operator !=(Complex& R){
return (real != R.real);
}

bool operator >(Complex& R){
return (real > R.real);
}
bool operator >=(Complex& R){
return (real >= R.real);
}

bool operator <(Complex& R){
return (real < R.real);
}
bool operator <=(Complex& R){
return (real <= R.real);
}
 operator int(){
return real;
}
operator char*(){


string rel = to_string(real);

string img = to_string(imagin);

string comp = rel + " + " + img +  "i " ;
char* ch = new char[comp.length()+1];
strcpy(ch,comp.c_str());


return ch;
}

};
Complex operator -(int L, Complex& R){
Complex result ;
result.SetReal(L - R.GetReal())  ;
return result ;
}


int main()
{
   Complex C1(1,2),C2(5),C3;
   C3 = C1.Sum(C2);
   C3.Print();
 cout<<"********************"<<endl;
   Complex C4;
   C4 = C1-C2;
   C4.Print();
 cout<<"********************"<<endl;
   C4 = 7-C2;
   C4.Print();
 cout<<"********************"<<endl;

   C4 = C2-7;
   C4.Print();
 cout<<"********************"<<endl;

   C1-=C2;
   C1.Print();
   cout<<"********************"<<endl;

   C1-=7;
   C1.Print();
 cout<<"********************"<<endl;
   C1--;
     C1.Print();
     cout<<"********************"<<endl;
  Complex C5;
  C5 = --C1;
     C5.Print();
     cout<<"********************"<<endl;
  C5 = C1--;
     C5.Print();
          cout<<"********************"<<endl;
          C1=C2;
        if(C1==C2)
cout<<"yes"<<endl;
else cout<<"no"<<endl;

cout<<"********************"<<endl;
//C1=C3;
        if(C1!=C3)
cout<<"yes"<<endl;
else cout<<"no"<<endl;
cout<<"********************"<<endl;
//C1=C3;
        if(C1>=C3)
cout<<"Greater"<<endl;
else cout<<"Less than"<<endl;

cout<<"********************"<<endl;

int x= (int)C1;
C1.Print();
cout << x << endl;

cout<<"********************"<<endl;
char* ch;
ch= (char*)C1;
cout << ch<< endl;

    return 0;

}
