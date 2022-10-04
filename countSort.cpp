//Count sort
#include<iostream>
using namespace std;
int getMax(int arr[],int n)//Find max element
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
       if(arr[i]>max)
       {
           max=arr[i];
       }
    }
    return max;
}
void countsrt(int arr[],int n)
{
    int max=getMax(arr,n);
    int count[max+1];//to store frequency of all elements
    for(int i=0;i<=max;i++)//initialize by 0
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)//count frequency
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++)//to store cumulative frequency 
    {
        count[i]=count[i]+count[i-1];
    }
   int output[n];
   for(int i=n-1;i>=0;i--)//store value at index shown in count array-1
   {
       output[--count[arr[i]]]=arr[i];
   }
   cout<<"Displaying array after sorting:";
   for(int i=0;i<n;i++)
   {
       cout<<output[i]<<" ";
   }
}
int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter the array size:";   
    cin>>n;
    int arr[n];
    cout<<"Enter the values:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    countsrt(arr,n);
    return 0;
}