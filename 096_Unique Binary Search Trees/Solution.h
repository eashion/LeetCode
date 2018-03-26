class Solution {
public:
    int numTrees(int n) {
        //n = 3;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[0] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                dp[i] += dp[j]*dp[i-1-j];
            }
            //cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};
