really smart algrithm. In maximum sum of sub array. We can solve it in O(n). The key point is remember the largest sum is either an array 
end of a[i], or a[i]. While in this problem, it's product. Numbers can be positive or negative. For positive number, it needs the largest 
product of previous subarray. For negative number, it needs the smallest previous subarray. So we need to record those two.
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //nums = {-1,2,-4};
        int res = 0;
        if (nums.size() == 0) {
            return res;
        }
        int positive = nums[0];
        int negative = nums[0];
        int cur = nums[0];
        res = cur;
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] < 0) 
                swap(positive, negative);
            positive = max(nums[i], positive*nums[i]);
            negative = min(nums[i], negative*nums[i]);
            res = max(positive, res);
        }
        return res;
    }
};
```
