class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> dp(n+1, 1);
        vector<int> nums;
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i-1]*i;
            nums.push_back(i);
        }
        string res = recursive(nums,n,dp,k-1);
        return res;
    }
private:
    string recursive(vector<int>& nums, int pos, vector<int> dp, int k){
        if (pos==1) {
            return to_string(nums[0]);
        }
        int cur = k/dp[pos-1];
        string res = to_string(nums[cur]);
        nums.erase(nums.begin()+cur);
        res += recursive(nums,pos-1,dp,k%dp[pos-1]);
        return res;
    }
};
