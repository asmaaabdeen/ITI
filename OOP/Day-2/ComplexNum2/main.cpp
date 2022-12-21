#include <iostream>

using namespace std;
class Complex
{
int real;
int imagin;
public:

    Complex(){
    real=6;imagin=9;
    cout<<"parameterless constructor of "<<this->real<<endl;
    }

    Complex(int x){
    real=x;imagin=x;
    cout<<"parameterize constructor of "<<this->real<<endl;
    }

    Complex(int x,int y){
    real=x;imagin=y;
        cout<<"parameterize constructor of "<<this->real<<endl;
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

~Complex(){
    cout<< "destructor of obj " << this->real << endl;
    }


};
/*Complex sub (Complex c1,Complex c2){
Complex result;
result.SetReal(c1.GetReal() - c2.GetReal())  ;
result.SetImag( c1.GetImag() - c2.GetImag());
return result;
}*/
int main()
{
   Complex C1(1,2),C2(5),C3;
   C3 = C1.Sum(C2);
   C3.Print();
    return 0;
}
