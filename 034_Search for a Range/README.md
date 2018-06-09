lower bound and upper bound
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //nums = {5,7,7,8,8,10};
        //target = 7;
        //nums = {-1};
        int left = -1;
        int right = nums.size();
        vector<int> res(2, -1);
        if (nums.size() == 0) 
            return res;
        while(left < right-1){
            int mid = (left+right)/2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (right<nums.size() && nums[right]==target) {
            res[0] = right;
        } else {
            return res;
        }
        left = -1;
        right = nums.size();
        while(left < right-1){
            int mid = (left+right)/2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (right-1>=0 && nums[right-1]==target) {
            res[1] = right-1;
        } else {
            res[0] = -1;
        }
        return res;
    }
};
```
