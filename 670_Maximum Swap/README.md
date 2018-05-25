Think one more step.
```
class Solution {
public:
    int maximumSwap(int num) {
        //num = 1993;
        vector<int> nums;
        while(num){
            nums.push_back(num%10);
            num /= 10;
        }
        int flag = -1;
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = i-1; j >= 0; j--){
                if (nums[j] > nums[i]) {
                    if (flag == -1) {
                        flag = j;
                    } else {
                        flag = nums[j]>=nums[flag]?j:flag;
                    }
                }
            }
            if (flag!=-1) {
                swap(nums[flag], nums[i]);
                break;
            }
        }
        int res = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            res = res*10+nums[i];
        }
        return res;
    }
};
```
