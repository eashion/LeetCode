#连成环后，最后一个和第一个一定不能同时选择。所以将原来的dp问题转换成了两个单独的问题，一个从0~n-2，一个从1~n-1
class Solution {
public:
    int rob(vector<int>& nums) {
        //nums = {1,2,1,4};
        if (nums.size()==0) {
            return 0;
        } else if (nums.size()==1) {
            return nums[0];
        }
        vector<int> opt(nums.size()+1, 0);
        opt[1] = nums[0];
        for(int i = 2; i < nums.size(); i++){
            opt[i] = max(opt[i-2]+nums[i-1], opt[i-1]);
        }
        int res = opt[nums.size()-1];
        //cout<<"res"<<res<<endl;
        opt[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){
            opt[i] = max(opt[i-2]+nums[i], opt[i-1]);
        }
        return max(res, opt[nums.size()-1]);
    }
};
