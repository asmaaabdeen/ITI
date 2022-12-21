#include <iostream>

using namespace std;
//insertion sort assumes first element of array is already sorted
//compare other elements to it if smaller place it in the left of the first element
//if greater place it on the right
void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
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
    insertionSort(Arr,7);
    PrintArr(Arr,7);

    return 0;
}
