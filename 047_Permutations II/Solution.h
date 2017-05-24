class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        dfs(0,nums.size(),nums,res);
        return res;
    }
private:
    void dfs(int cur,int deep,vector<int> nums,vector<vector<int>>& res){
        if( cur == deep ){
            res.push_back(nums);
            return ;
        }
        for( int i = cur; i < deep; i++ ){
            if( i!=cur && nums[i]==nums[cur] ){
                continue;
            }
            swap(nums[i],nums[cur]);
            dfs(cur+1,deep,nums,res);
        }
    }
};
