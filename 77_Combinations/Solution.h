class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(n,k,0,0,tmp,res);
        return res;
    }
private:
    void dfs(int n,int k,int pos,int deep,vector<int>& tmp,vector<vector<int>>& res){
        if( deep == k ){
            res.push_back(tmp);
        }
        for( int i = pos+1; i <= n; i++ ){
            tmp.push_back(i);
            dfs(n,k,i,deep+1,tmp,res);
            tmp.pop_back();
        }
        return ;
    }
};
