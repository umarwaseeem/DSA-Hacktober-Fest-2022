// 0-1 knapsack problem
#include <iostream>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{ 
       long long int dp[n+1][w+1];
       for(long long int i=0;i<w+1;i++)
       dp[0][i]=0;
       for(long long int i=0;i<n+1;i++)
       dp[i][0]=0;
       
       for(long long int j=1;j<w+1;j++)
       {
           for(long long int i=1;i<n+1;i++)
           {
               if(j>=wt[i-1])
               dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
               else
               dp[i][j]=dp[i-1][j];
           }
       }
       
       return dp[n][w];
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}