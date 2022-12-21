#include <iostream>

using namespace std;

template<class t>
class intArray{
t *Arr;
int Size;

public:
    intArray(int s=7){
    Size=s;
    Arr = new t[Size];
    for(int i=0;i<Size;i++)
        Arr[i]=0;
    }

    /********************************************/

    ~intArray(){
         cout <<"destructor of " << this->Arr[0]<<endl;
    for(int i=0 ; i<Size ;i++)
        Arr[i]=-1;

    delete []Arr;

    }

    /******************************************/

    intArray(const intArray& oldA){
    Size= oldA.Size;
    Arr= new t[Size];
    }

    /******************************************/

    int getSize(){
    return Size;
    }

    /*****************************************/

    void setValue (int index,t Value){
    if((index>=0)&&(index<Size))
        Arr[index]=Value;
        else cout << "invalid index"<<endl;
    }

    /*****************************************/

    t getValue(int index){
    if((index>=0)&&(index<Size))
        return Arr[index];
    else {cout << "invalid index"<<endl;
    return -1;}
    }

    /*****************************************/

    t operator[](int index){
    if((index>=0)&&(index<Size))
        return Arr[index];
    else {cout << "invalid index"<<endl;
    return -1;}
    }
    /*****************************/

    intArray& operator= (const intArray& R){
        delete []Arr;

        Arr = new t[Size];
    for(int i =0;i<Size ;i++){
        Arr[i]=R.Arr[i];
    }
    return *this;
    }

    /**************************************/

    intArray operator + (const intArray& R){
        intArray result(7);
    for(int i=0;i<Size; i++)
        result.Arr[i]=Arr[i] + R.Arr[i];

    return result;
    }
};
int main()
{
   intArray<int> MyArr(7);
   MyArr.setValue(0,1);
   MyArr.setValue(1,2);
   MyArr.setValue(2,3);
   MyArr.setValue(3,4);

   for(int i =0;i<MyArr.getSize();i++){
    cout<< MyArr[i] <<endl;
   }
cout<<"********************"<<endl;
   intArray<int> Arr2(7);
   Arr2=MyArr;

   for(int i =0;i<Arr2.getSize();i++){
    cout<< Arr2[i] <<endl;
   }
   cout<<"********************"<<endl;
   for(int i =0;i<MyArr.getSize();i++){
    cout<< MyArr[i] <<endl;
   }
   cout<<"********************"<<endl;
   intArray<int> Arr3 (7);

   Arr3= MyArr + Arr2;

    for(int i =0;i<Arr3.getSize();i++){
    cout<< Arr3.getValue(i) <<endl;
   }
   cout<<endl<<"********************"<<endl;
   intArray<char> chArr(7);
   chArr.setValue(0,'a');
   chArr.setValue(1,'l');
   chArr.setValue(2,';');
   chArr.setValue(3,'.');

   for(int i =0;i<chArr.getSize();i++){
    cout<< chArr[i] <<endl;
   }
cout<<"********************"<<endl;
   intArray<char> chArr2(7);
   chArr2=chArr;

   for(int i =0;i<chArr2.getSize();i++){
    cout<< chArr2[i] <<endl;
   }
   cout<<"********************"<<endl;
   for(int i =0;i<chArr.getSize();i++){
    cout<< chArr[i] <<endl;
   }
   cout<<"********************"<<endl;
   intArray<char> chArr3 (7);

   chArr3= chArr + chArr2;

    for(int i =0;i<chArr3.getSize();i++){
    cout<< chArr3.getValue(i) <<endl;
   }
    return 0;
}
