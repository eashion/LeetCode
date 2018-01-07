class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int inLine[10];
        vector<int> cur;
        vector<vector<int> > res;
        findCombination(0,0,k,n,cur,res,inLine);
        return res;
    }
    void findCombination(int sum,int cnt,int k,int n,vector<int> cur,vector<vector<int> > &res,int *inLine){
        if (sum==n && cnt==k) {
            res.push_back(cur);
            return ;
        }
        if(cnt==k){
            return ;
        }
        int last = 0;
        if (cnt!=0) {
            last = cur.back();
        }
        for( int i = last+1; i < 10; i++ ){
            if (inLine[i]==1) {
                continue;
            }
            if (sum+i <= n) {
                inLine[i] = 1;
                cur.push_back(i);
                findCombination(sum+i,cnt+1,k,n,cur,res,inLine);
                cur.pop_back();
                inLine[i] = 0;
            }
        }
        return ;
    }
};


class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
};
