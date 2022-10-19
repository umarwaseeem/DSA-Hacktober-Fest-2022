class Solution {
public:
    int t[51][51][51];
    int mod = pow(10,9) + 7;
    int solve(int m, int n, int maxMove, int startRow, int startColumn) {
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n) return 1;
        if(maxMove<=0) return 0;
        if(t[maxMove][startRow][startColumn]!=-1) return t[maxMove][startRow][startColumn]%mod;
        int ans = 0;
        ans= (ans + solve(m,n,maxMove - 1,startRow - 1,startColumn))%mod;
        ans = (ans+ solve(m,n,maxMove - 1,startRow + 1,startColumn))%mod;
        ans = (ans +solve(m,n,maxMove - 1,startRow ,startColumn - 1))%mod;
        ans = (ans +solve(m,n,maxMove - 1,startRow,startColumn + 1))%mod;
        return t[maxMove][startRow][startColumn] = (ans)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(t,-1,sizeof(t));
        return solve(m,n,maxMove,startRow,startColumn)%mod;
    }
};
