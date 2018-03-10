#dp, the only thing you need to care about is if cur-1 choosed.
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<vector<int>> dp(10001, vector<int>(2, 0));
        vector<pair<int,int>> lis;
        sort(nums.begin(), nums.end());
        int sum = 0;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            if (cur==0) {
                cur = nums[i];
                sum = cur;
            } else if (nums[i]==cur) {
                sum += nums[i];
            } else {
                lis.push_back(make_pair(cur,sum));
                cur = nums[i];
                sum = nums[i];
            }
        }
        lis.push_back(make_pair(cur,sum));
        int pos = 0;
        int res = 0;
        dp[lis[0].first][0] = 0;
        dp[lis[0].first][1] = lis[0].second;
        res = lis[0].second;
        for(int i = 1; i < lis.size(); i++){
            int cur = lis[i].first;
            dp[cur][0] = dp[cur-1][1]==0? res:max(dp[cur-1][0],dp[cur-1][1]);
            dp[cur][1] = dp[cur-1][1]==0? res+lis[i].second:dp[cur-1][0]+lis[i].second;
            res = max(res, dp[cur][1]);
        }
        return res;
    }
};
