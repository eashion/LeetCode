#按照层次dp，也可以使用recursion。不需要计算出sum，每层相减。看结果是否为正值。
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        //nums = {1,5,233,7};
        int sum = 0;
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            dp[i][i] = nums[i];
        }
        for(int k = 0; k < nums.size(); k++){
            for(int i = 0; i < nums.size()-k; i++){
                int j = i+k;
                if (k==0) {
                    dp[i][j] = nums[i];
                } else if (k==1) {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                } else {
                    dp[i][j] = max(nums[i]+min(dp[i+2][j],dp[i+1][j-1]), nums[j]+min(dp[i+1][j-1],dp[i][j-2]));
                }
            }
        }
        //for(int i = 0; i < nums.size(); i++){
        //    for(int j = 0; j < nums.size(); j++){
        //        cout<<dp[i][j]<<',';
        //    }
        //    cout<<endl;
        //}
        sum -= dp[0][nums.size()-1];
        return dp[0][nums.size()-1]>=sum;
    }
};
public class Solution {
    public boolean PredictTheWinner(int[] nums) {
        return helper(nums, 0, nums.length-1, new Integer[nums.length][nums.length])>=0;
    }
    private int helper(int[] nums, int s, int e, Integer[][] mem){    
        if(mem[s][e]==null)
            mem[s][e] = s==e ? nums[e] : Math.max(nums[e]-helper(nums,s,e-1,mem),nums[s]-helper(nums,s+1,e,mem));
        return mem[s][e];
    }
}
