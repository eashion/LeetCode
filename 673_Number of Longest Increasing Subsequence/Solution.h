class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 1);
        vector<int> cnt(nums.size()+1, 1);
        int maxInc = 1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if (nums[i]>nums[j]) {
                    if (dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j]+1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxInc = max(dp[i], maxInc);
        }
        for(int i = 0; i < nums.size(); i++){
            if (dp[i]==maxInc) {
                res += cnt[i];
            }
        }
        return res;
    }
};
