class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(100*200, 0);
        int sum = 0;
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            for(int j = sum; j >= nums[i]; j--)
                if (dp[j]==0) 
                    dp[j] = dp[j-nums[i]]==1 ? 1:0;
        }
        if (sum%2==1)
            return false;
        return dp[sum/2]==1? true:false;
    }
};
