```
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0;
        int pos;
        for(int i = 0; i < nums.size(); i++){
            if (largest < nums[i]) {
                largest = nums[i];
                pos = i;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if (pos == i) {
                continue;
            }
            if (largest < nums[i]*2) {
                return -1;
            }
        }
        return pos;
    }
};
```
