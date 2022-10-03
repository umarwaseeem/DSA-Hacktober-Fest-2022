#include<iostream>
using namespace std;

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i] <<" ";
    }cout<<endl;
}
void swapx(int arr[],int n)
{
    for(int i=0;i<n;i+=2)
    {
        if(i+1<n)
        {
           // swap(arr[i],arr[i+1]);
           //use any one for swapping
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
}

int main()
{
    int even[8] = {5,3,6,5,7,8,4,0};
    int odd[5] = {43,54,6,3,7};
    swapx(even, 8);
    printarray(even,8);
    swapx(odd, 5);
    printarray(odd,5);
    

    return 0;
    
}
