think one more step
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //nums = {1,0};
        int pos = -1;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) {
                pos = max(pos, i);
                for(int j = pos+1; j < nums.size(); j++){
                    if (nums[j] != 0) {
                        pos = j;
                        break;
                    }
                }
                if (nums[pos] == 0) 
                    break;
                swap(nums[i], nums[pos]);
            }
        }
        return ;
    }
};
```
