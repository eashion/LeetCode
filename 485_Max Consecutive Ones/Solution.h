class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                nums[i] = nums[i-1]+1;
            } else {
                nums[0] = max(nums[0],nums[i-1]);
            }
        }
        nums[0] = max(nums[0],nums[nums.size()-1]);
        return nums[0];
    }
};
