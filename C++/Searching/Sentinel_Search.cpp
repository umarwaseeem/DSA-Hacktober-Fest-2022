#include <bits/stdc++.h>
using namespace std;
 
void sentinel_search(vector<int> arr ,int search)
{
    int n = arr.size();
    int last = arr[n - 1];
 
    arr[n - 1] = search;
    int i = 0;
 
    while (arr[i] != search){
        i++;   
    }
     
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == search))
    {
        cout<<"\nElement is present at index : "<<i<<"\n";
    }
    else
    {
        cout<<"\nElement Not found\n";
    }
        
}
 
void display(vector <int> a)
{
    cout<<"\nArray\n";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void accept_elements(vector <int> &a)
{
    int n,x;
    cout<<"Enter size of array : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element "<<i<<" : ";
        cin>>x;
        a.push_back(x);
    }
    display(a);
}

int main()
{
    vector <int> arr;
    int search;
    accept_elements(arr);
    cout<<"Enter the element you want to serach : ";
    cin>>search;
    sentinel_search(arr,search);
 
    return 0;
}
