#这道题目还是比较巧妙地，因为最开始在考虑的时候变量太多了。每次增加一杯，而且还要考虑行数和列数。最开始想要贪心，但是发现越往后情况越复杂，没办法贪。
#参考了discuss。把倒了多少杯固定下来。下一层和上一层始终是(dp[i]-1/2)的关系。同时滚动数组dp[i]也是下一行的dp[i]=(dp[i]-1)/2。
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int idx = 0;
        //poured = 2;
        //query_row = 1;
        //query_glass = 1;
        vector<double> dp(100, 0.0);
        dp[0] = poured;
        for(int row = 1; row <= query_row; row++){
            for(int i = row; i >= 0; i--){
                dp[i] = max(0.0, (dp[i]-1)/2);
                dp[i+1] += dp[i];
            }
        }
        return min(1.0, dp[query_glass]);
    }
};
