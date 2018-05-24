```
class Solution {
public:
    int findMin(vector<int>& nums) {
        //nums = {5,1,2,3,4};
        //nums = {4,5,6,7,0,1,2};
        if (nums[0] < nums[nums.size()-1]) {
            return nums[0];
        }
        long left = 0;
        long right = nums.size()-1;
        while(1 < right-left){
            long mid = (left+right)/2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return nums[right];
    }
};
```
