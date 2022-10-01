
public class Main {
    public static void main(String[] args) {
        String s1 = "abcd";
        String s2 = "bd";
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int n = c1.length;
        int m = c2.length;

        int[][] dp = new int[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (c1[i-1] == c2[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        System.out.println(dp[n][m]);
        char[] s = new char[dp[n][m]];
        int count = dp[n][m]-1;
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(c1[i-1]!=c2[j-1]){
               if(dp[i-1][j]>dp[i][j-1]){
                   i=i-1;
               }else{
                   j=j-1;
                        }
            }
            else{
                s[count--]=c1[i-1];
                j=j-1;
                i=i-1;
            }
        }
                System.out.println(s);

    }
}


/// Using Recurison

public class Main {
    public static int LCS(int i, int j, char[] s1, char[] s2, int[][] dp){
        if(i==0 || j==0){
            return 0;
        }
        else if(dp[i][j]!='\0') return dp[i][j];
        else if(s1[i-1]==s2[j-1]){
            return dp[i][j] = 1+LCS(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j] = Math.max(LCS(i-1,j,s1,s2,dp),LCS(i,j-1,s1,s2,dp));
        }
    }
    public static void main(String[] args) {
        String s1= "abcd";
        String s2 = "bd";
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int[][] dp = new int[c1.length+1][c2.length+1];
        int ans = LCS(c1.length,c2.length,c1,c2,dp);
        System.out.println(ans);
    }
}