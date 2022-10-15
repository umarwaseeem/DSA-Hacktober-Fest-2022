// Nth catalan number
#include <bits/stdc++.h>
using namespace std;

int findCatalan(int n) 
{
    int dp[n+1]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i-1;j++)
        dp[i]+=(dp[j]*dp[i-1-j]);
    }
    return dp[n];
}

int main()
{
    for (int i = 0; i < 10; i++)
    cout <<findCatalan(i) << " ";
    return 0;
}