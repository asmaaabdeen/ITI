#include <iostream>

using namespace std;

void swap(int &x,int &y){
int temp;
temp = x;
x=y;
y=temp;
}

void merge(int arr[], int  lfirst, int  llast,int rfirst,
           int  rlast)
{
   int* tempArr = new int[sizeof(arr)];
   int index = lfirst;
   int SaveFirst = lfirst;

   while((lfirst<=llast)&&(rfirst<=rlast))
   {
       if(arr[lfirst]<arr[rfirst])
        tempArr[index++]=arr[lfirst++];
       else
        tempArr[index++] = arr[rfirst++];
   }

   while (lfirst <= llast)
    tempArr[index++]=arr[lfirst++];

   while (rfirst<=rlast)
    tempArr[index++] = arr[rfirst++];

   for(int i = SaveFirst ; i<=rlast;i++)
    arr[i]=tempArr[i];
}

void mergeSort(int arr[], int first, int  last)
{
    if (first >= last)
        return; // Returns recursively

    int mid = (first + last) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid,mid+1, last);
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
    mergeSort(Arr,0,6);
    PrintArr(Arr,7);

    return 0;
}
