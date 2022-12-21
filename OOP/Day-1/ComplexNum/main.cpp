#include <iostream>

using namespace std;
class Complex
{
int real;
int imagin;
public:
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
};
Complex sub (Complex c1,Complex c2){
Complex result;
result.SetReal(c1.GetReal() - c2.GetReal())  ;
result.SetImag( c1.GetImag() - c2.GetImag());
return result;
}
int main()
{
    Complex c1,c2,c3,c4;
    c1.SetReal(3);
    c1.SetImag(-3);
    cout <<"first complex number = " ;
    c1.Print();

cout<<endl;

    c2.SetReal(-3);
    c2.SetImag(5);
    cout <<"second complex number = " ;
    c2.Print();

cout<<endl;

    c3 = c1.Sum(c2);
    cout <<"Sum complex numbers = " ;
    c3.Print();

cout<<endl;

    c4 = sub(c3,c1);
    cout <<"Sub complex numbers = " ;
    c4.Print();
    return 0;
}
