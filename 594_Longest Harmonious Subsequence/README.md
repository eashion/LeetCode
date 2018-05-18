最开始想要用dp，但是dp不能保存1的关系。sort之后比较，其实最简单的是放到map里面然后去遍历map。
```
class Solution {
public:
    int findLHS(vector<int>& nums) {
        //nums = {1,1,1,1,3};
        sort(nums.begin(), nums.end());
        int pre = 0;
        int cur = 0;
        int res = 0;
        vector<int> sta;
        for(int i = 0; i < nums.size(); i++){
            if (i>0 && nums[i]!=nums[i-1]) {
                if (sta.size()!=0 && nums[i-1]==sta[sta.size()-1]+1) {
                    res = max(res,cur+pre);
                }
                sta.push_back(nums[i-1]);
                pre = cur;
                cur = 0;
            }
            cur++;
        }
        if (sta.size()!=0 && nums[nums.size()-1]==sta[sta.size()-1]+1) {
            res = max(res,cur+pre);
        }
        return res;
    }
};
```
