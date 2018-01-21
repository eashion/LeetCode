/*class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            res = max(res,dp[i]);
        }
        return res;
    }
};*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return devideAndConquer(nums,0,nums.size()-1);
    }
private:
    int devideAndConquer(vector<int> nums,int left,int right){
        if (left==right) {
            return nums[left];
        }
        int mid = (left+right)>>1;
        int lres = devideAndConquer(nums,left,mid);
        int rres = devideAndConquer(nums,mid+1,right);
        if (lres<0 && rres<0) {
            return max(lres,rres);
        } else if (lres<0) {
            return rres<0 ? 0:rres;
        } else if (rres<0) {
            return lres<0 ? 0:lres;
        }
        int lpar = INT_MIN;
        int rpar = INT_MIN;
        int pre = 0;
        for(int i = mid; i >= left; i--){
            pre += nums[i];
            lpar = max(pre,lpar);
        }
        pre = 0;
        for(int i = mid+1; i <= right; i++){
            pre += nums[i];
            rpar = max(pre,rpar);
        }
        return max(max(lres,rres),lpar+rpar);
    }
};
