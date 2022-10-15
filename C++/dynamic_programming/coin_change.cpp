// coin change problem
#include <bits/stdc++.h>
using namespace std;


long long int count(int S[], int n, int m) {
       
       long long dp[n+1][m+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++)
           {
               if(i==0)
               dp[i][j]=0;
               if(j==0)
               {
                   dp[i][j]=1;
               }
           }
       }
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(S[i-1]>j)
               dp[i][j]=dp[i-1][j];
               else
               dp[i][j]=dp[i-1][j]+dp[i][j-S[i-1]];
           }
       }
       return dp[n][m];
    
}
int main()
{
    int i, j;
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;
 
    cout << " " << count(coins, n, sum);
 
    return 0;
}