#include<iostream>
using namespace std;
int main()
{
         cout<<sizeof(int)<<"\n";
         cout<< sizeof(char)<<"\n";
         cout<<sizeof(float)<<endl;
         cout<<sizeof(double)<<endl;
         cout<<sizeof(long long)<<endl;
         cout<<sizeof(string)<<endl;
         cout<<sizeof(bool)<<endl;
         cout<<sizeof(string)<<endl;
         cout<<sizeof(0.2)<<endl;
         cout<<sizeof(7)<<endl;
         int x=10;
         cout<<sizeof(x++)<<endl;//compile time oprator so its value remain same.
         cout<<x<<endl;
         cout<<sizeof(6.9f)<<endl;
         cout<<sizeof(10ll)<<endl;
         
         return 0;

}
