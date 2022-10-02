#include<iostream>
using namespace std;

void selectionSort(int array[], int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;   //get index of minimum element
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;
         swap(array[i], array[imin]);
   }
}

void coutSortedArr(int array[], int size) {
   for(int i = 0; i<size; i++)
      cout<<array[i]<<" ";
   
}

int main() {
   int n;
   cin >> n;
   int arr[n];  
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   selectionSort(arr, n);
   cout<<"The sorted array is: ";
   for(int i = 0; i<n; i++)
      cout<<arr[i]<<" ";
}