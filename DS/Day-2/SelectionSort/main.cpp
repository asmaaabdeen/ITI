#include <iostream>

using namespace std;

void swap(int &x,int &y){
int temp;
temp = x;
x=y;
y=temp;
}

void SelectionSort(int *arr,int Size ){
int minIdx;
for(int i = 0;i<Size-1;i++){
    minIdx = i;
for(int j =i+1;j<Size;j++){
    if(arr[j]<arr[minIdx])
        minIdx = j;
}
swap(arr[i],arr[minIdx]);
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
    SelectionSort(Arr,7);
    PrintArr(Arr,7);

    return 0;
}
