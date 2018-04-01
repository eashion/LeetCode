class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> opt(nums.size()+1, 0);
        opt[0] = 1;
        int top = 0;
        for(int i = 0; i < nums.size(); i++){
            if (i>top) {
                return false;
            }
            top = max(top, i+nums[i]);
            if (top>nums.size()) {
                break;
            }
        }
        return true;
    }
};
