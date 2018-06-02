dfs. one little trick, start from the back.
```
class Solution {
public:
    int countArrangement(int N) {
        //N = 12;
        int res = 0;
        vector<int> used(N+1, 0);
        vector<int> arrange(N+1, 0);
        vector<vector<int>> legal(N+1, vector<int>());
        initialLegal(N, legal);
        dfs(N,res,N,arrange,used,legal);
        return res;
    }
private:
    void initialLegal(int N, vector<vector<int>>& legal){
        for(int i = 1; i <= N; i++){
            legal[i].push_back(i);
            for(int j = i+1; j <= N; j++){
                if (j%i == 0) {
                    legal[i].push_back(j);
                    legal[j].push_back(i);
                }
            }
        }
        return ;
    }
    void dfs(int N, int& res, int pos, vector<int>& arrange, vector<int>& used, vector<vector<int>> legal){
        if (pos == 0) {
            res++;
            return ;
        }
        //cout<<"pos: "<<pos<<endl;
        for(int i = 0; i < legal[pos].size(); i++){
            if (used[legal[pos][i]] == 0) {
                //cout<<"use: "<<legal[pos][i]<<endl;
                arrange[pos] = legal[pos][i];
                used[legal[pos][i]] = 1;
                dfs(N,res,pos-1,arrange,used,legal);
                used[legal[pos][i]] = 0;
            }
        }
        return ;
    }
};
```
