#include <iostream>

using namespace std;

void swap(int &x,int &y){
int temp;
temp = x;
x=y;
y=temp;
}

void BubbleSortAsc(int Arr[],int n){
bool flag=true;

for(int i=0;i<n-1;i++){
    for(int j=0;j<n-1-i;j++){
        if(Arr[j]>Arr[j+1])
        {
            swap(Arr[j],Arr[j+1]);
            flag = false;
        }
    }
    if (flag == true)
        break;
}
}



void PrintArr(int *arr,int Size){
for(int i =0;i<Size;i++){
    cout<< arr[i] <<" , ";
}
cout <<endl;
}

int main()
{
    int Arr[] = {50,21,9,78,0,33,6};
    PrintArr(Arr,7);
    BubbleSortAsc(Arr,7);
    PrintArr(Arr,7);
    return 0;
}
