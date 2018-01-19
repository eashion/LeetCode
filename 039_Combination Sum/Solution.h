class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(0,0,cur,candidates,target,res);
        return res;
    }
private:
    void dfs(int sum,int pos,vector<int> cur,vector<int> candidates,int target,vector<vector<int>>& res){
        if (sum==target) {
            res.push_back(cur);
        }
        for(int i = pos; i < candidates.size(); i++){
            if (sum+candidates[i] <= target) {
                cur.push_back(candidates[i]);
                dfs(sum+candidates[i],i,cur,candidates,target,res);
                cur.pop_back();
            }
        }
        return ;
    }
};

class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
