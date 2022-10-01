public class Main {
    public static void main(String[] args) {
        String s1 = "abcdxydfgdjfjdifdjdi";
        String s2 = "jfjdif";
        int maxI=0;
        int maxJ=0;
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        int n = c1.length;
        int m = c2.length;
        int max =0;
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
                    dp[i][j] = 0;
                }
               if(dp[i][j]>= max){
                   max=dp[i][j];
                   maxI=i;
                   maxJ=j;
               }
            }
        }
        char[] s = new char[max];
        int count = max-1;
        while(maxI>0 &&maxJ>0){
            if(c1[maxI-1] == c2[maxJ-1]){
                s[count--]=c1[maxI-1];
                maxI--;
                maxJ--;
            }else{
                maxI--;
                maxJ--;
            }
        }
    System.out.println(s);
    System.out.println(max);

    }
}