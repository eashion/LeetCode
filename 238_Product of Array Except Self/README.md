Think one more step.
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        long times = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] *= times;
            times *= nums[i];
        }
        times = 1;
        for(int i = nums.size()-1; i >= 0; i--){
            res[i] *= times;
            times *= nums[i];
        }
        return res;
    }
};
```
