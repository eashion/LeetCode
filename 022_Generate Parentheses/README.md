```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("",0,n,res);
        return res;
    }
private:
    void dfs(string ans,int cur,int n,vector<string>& res){
        //cout<<ans<<endl;
        if (ans.length()==2*n) {
            if (cur == 0) {
                res.push_back(ans);
            }
            return ;
        }
        if (cur<n && cur<=(2*n-ans.length())) {
            dfs(ans+"(",cur+1,n,res);
        }
        if (cur > 0) {
            dfs(ans+")",cur-1,n,res);
        }
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int sum = pow(2,2*n);
        for(int i = 0; i < sum; i++){
            string cur = check(i,n);
            if (cur != "") {
                res.push_back(cur);
            }
        }
        return res;
    }
private:
    string check(int num,int n){
        int sum = 0;
        int cnt = 2*n;
        string ans = "";
        while(cnt--){
            int cur = num%2;
            num /= 2;
            sum += cur==0?-1:1;
            ans += cur==0?")":"(";
            if (sum<0 || sum>n || (cnt<sum)) {
                return "";
            }
        }
        return sum==0?ans:"";
    }
};
```
