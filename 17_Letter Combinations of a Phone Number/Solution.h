class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string num[11];
        num[2] = "abc";
        num[3] = "def";
        num[4] = "ghi";
        num[5] = "jkl";
        num[6] = "mno";
        num[7] = "pqrs";
        num[8] = "tuv";
        num[9] = "wxyz";
        num[0] = " ";
        dfs(digits,"",0,res,num);
        return res;
    }
private:
    void dfs(string digits,string cur,int deep,vector<string>& res,string num[]){
        if( deep == digits.size() ){
            if( cur != "" ){
                res.push_back(cur);
            }
            return ;
        }
        string tmp = num[digits[deep]-'0'];
        for( int i = 0; i < tmp.length(); i++ ){
            dfs(digits,cur+tmp[i],deep+1,res,num);
        }
    }
};
