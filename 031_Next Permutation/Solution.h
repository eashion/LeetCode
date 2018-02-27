class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return ;
        }
        int pos = -1;
        for(int i = size-1; i > 0; i--){
            if (nums[i]>nums[i-1]) {
                pos = i-1;
                break;
            }
        }
        if (pos==-1) {
            reverse(nums.begin(), nums.end());
        } else{
            int tmp = -1;
            for(int i = size-1; i > pos; i--){
                if (nums[i]>nums[pos]) {
                    tmp = i;
                    break;
                }
            }
            swap(nums[pos], nums[tmp]);
            reverse(nums.begin()+pos+1, nums.end());
        }
        return ;
    }
};
