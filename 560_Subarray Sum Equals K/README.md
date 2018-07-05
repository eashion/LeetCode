O(n^2) is the worst time complexity. Each element in the array can be positive or negative. So greedy is also a bad idea. So we should try to 
find a O(nlgn) time complexity algorithm. lgn is not just from divide and conquer, but also the search complexity of map. From this prospect, 
what we need is the current prefix sum, and search how many sum-k is satisfied. Also remember to add the number sum equals k.
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // nums = {1,0,1,0,1,0,1};
        // nums = {1,2,3};
        // k = 3;
        // nums = {1};
        // k = 0;
        int res = 0;
        int len = nums.size();
        if (len == 0) {
            return res;
        }
        map<int, int> mm;
        int sum = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
            res += mm[sum-k];
            mm[sum] += 1;
        }
        res += mm[k];
        return res;
    }
};
```
