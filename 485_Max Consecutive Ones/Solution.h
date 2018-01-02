class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = nums[0]==1?1:0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                nums[i] = nums[i-1]+1;
            } else {
                res = max(res,nums[i-1]);
            }
        }
        res = max(res,nums[nums.size()-1]);
        return res;
    }
};
