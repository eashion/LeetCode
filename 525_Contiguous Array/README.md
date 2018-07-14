In the first view, it's a problem of prefix array. I want use the non-decreasing of prefix array to find the O(lgn). While for every pos, 
even the prfix array is non-decreasing, there are still prefix[i] possibilities. So the total complexity is O(n^2lgn). According to the discussion, 
change 0 to -1, then the problem can transfer to find if the prefix sum ocured before, and same as, sum[x,y]=0. And the lgn comes from map.
```
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // nums = {0,1,0,1,1,0,1,0};
        int res = 0;
        int len = nums.size();
        if (len == 0) {
            return res;
        }
        map<int, int> mm;
        mm[0] = -1;
        int sum = 0;
        for(int i = 0; i < len; i++){
            // cout<<"pos: "<<i;
            sum += nums[i]==0 ? -1 : 1;
            if (mm.find(sum) != mm.end()) {
                res = max(res, i-mm[sum]);
            } else {
                mm[sum] = i;
            }
        }
        return res;
    }
};
```
