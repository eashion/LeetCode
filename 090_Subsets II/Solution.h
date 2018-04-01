class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //nums = {4,4,4,1,4};
        vector<vector<int>> res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if (i==0 || nums[i]!=nums[i-1]) {
                cur.push_back(nums[i]);
                findSubset(i,cur,nums,res);
                cur.pop_back();
            }
        }
        res.push_back(vector<int>(0, 0));
        return res;
    }
private:
    void findSubset(int pos, vector<int> cur, vector<int> nums, vector<vector<int>>& res){
        res.push_back(vector<int>(cur.begin(), cur.end()));
        for(int i = pos+1; i < nums.size(); i++){
            if (i==pos+1 || nums[i]!=nums[i-1]) {
                cur.push_back(nums[i]);
                findSubset(i,cur,nums,res);
                cur.pop_back();
            }
        }
        return ;
    }
};
