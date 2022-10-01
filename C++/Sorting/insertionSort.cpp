#include<iostream>
using namespace std;

int main(){
    int n,key,j;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        key=arr[i];
        for( j=i-1;j>=0 && arr[j]>key;j--){
            arr[j + 1] = arr[j];
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}