#include <iostream>

using namespace std;
class intArray{
int *Arr,Size;

public:
    intArray(int s=7){
    Size=s;
    Arr = new int[Size];
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
    Arr= new int[Size];
    }

    /******************************************/

    int getSize(){
    return Size;
    }

    /*****************************************/

    void setValue (int index,int Value){
    if((index>=0)&&(index<Size))
        Arr[index]=Value;
        else cout << "invalid index"<<endl;
    }

    /*****************************************/

    int getValue(int index){
    if((index>=0)&&(index<Size))
        return Arr[index];
    else {cout << "invalid index"<<endl;
    return -1;}
    }

    /*****************************************/

    int operator[](int index){
    if((index>=0)&&(index<Size))
        return Arr[index];
    else {cout << "invalid index"<<endl;
    return -1;}
    }
    /*****************************/

    intArray& operator= (const intArray& R){
        delete []Arr;

        Arr = new int[Size];
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
   intArray MyArr(7);
   MyArr.setValue(0,1);
   MyArr.setValue(1,2);
   MyArr.setValue(2,3);
   MyArr.setValue(3,4);

   for(int i =0;i<MyArr.getSize();i++){
    cout<< MyArr[i] <<endl;
   }
cout<<"********************"<<endl;
   intArray Arr2(7);
   Arr2=MyArr;

   for(int i =0;i<Arr2.getSize();i++){
    cout<< Arr2[i] <<endl;
   }
   cout<<"********************"<<endl;
   for(int i =0;i<MyArr.getSize();i++){
    cout<< MyArr[i] <<endl;
   }
   cout<<"********************"<<endl;
   intArray Arr3 (7);

   Arr3= MyArr + Arr2;

    for(int i =0;i<Arr3.getSize();i++){
    cout<< Arr3.getValue(i) <<endl;
   }
    return 0;
}
