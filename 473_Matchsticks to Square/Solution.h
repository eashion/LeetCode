class Solution {
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if (sum==0 || sum%4!=0) {
            return false;
        }
        sum /= 4;
        vector<int> used(nums.size(),0);
        for(int i = nums.size()-1; i >= 0; i--){
            if(used[i]==0){
                used[i] = 1;
                bool flag = checkFit(nums[i],sum,used,nums);
                if (!flag) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool checkFit(int cur,int sum,vector<int> &used,vector<int> nums){
        if (cur==sum) {
            return true;
        }
        for(int i = nums.size()-1; i >= 0; i--){
            if(used[i]==0 && cur+nums[i]<=sum){
                used[i] = 1;
                bool flag = checkFit(cur+nums[i],sum,used,nums);
                if (flag) {
                    return flag;
                } else {
                    used[i] = 0;
                }
            }
        }
        return false;
    }
};
