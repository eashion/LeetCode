class Solution {
public:
    int numSquares(int n) {
        int sta = sqrt(n);
        int dp[n+1];
        dp[0] = 0;
        for( int i = 1; i <= n; i++ ){
            dp[i] = 0x7fffffff;
        }
        for( int i = 0; i <= n; i++ ){
            for( int j = 1; j <= sta; j++ ){
                int tmp = j*j+i;
                if( tmp <= n ){
                    dp[tmp] = min(dp[tmp],dp[i]+1);
                }
                else{
                    break;
                }
            }
        }
        return dp[n];
    }
};
