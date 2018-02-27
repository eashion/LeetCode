#这道题目开始的时候从各个方向找角度，这个尝试是好的。想到过dp，但是没有坚持下去。可能当时想的是dp的维度，不是按照strs，而是m和n。0-1背包。
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        vector<int> ones(strs.size(), 0);
        vector<int> zeros(strs.size(), 0);
        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j]=='1'){
                    ones[i]++;
                } else{
                    zeros[i]++;
                }
            }
        }
        for(int i = 0; i < strs.size(); i++){
            for(int x = m; x >= zeros[i]; x--){
                for(int y = n; y >= ones[i]; y--){
                    dp[x][y] = max(dp[x-zeros[i]][y-ones[i]]+1, dp[x][y]);
                }
            }
        }
        return dp[m][n];
    }
};
