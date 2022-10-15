/*Given two integers n and r, find nCr. Since the answer may be
very large, calculate the answer modulo 109+7.*/
#include <bits/stdc++.h>
using namespace std;


int nCr(int n, int r)
{
        if(r>n)
        return 0;
        if(n-r<r)
        r=n-r;
        int M=1e9+7;
        int dp[r+1];
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=min(i,r);j>=0;j--)
            {
                if(j==0)
                dp[j]=1;
                else
                dp[j]=(dp[j-1]+dp[j])%M;
            }
        }
        return dp[r];
}
int main()
{
    int n = 5, r = 3;
    cout << nCr(n, r);
    return 0;
}