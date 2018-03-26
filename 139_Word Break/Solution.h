class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> opt(s.length()+1, -1);
        opt[0] = 0;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if (opt[j]!=-1 && check(j+1,i,s,wordDict)) {
                    opt[i] = opt[j]+1;
                }
            }
        }
        return opt[s.length()]!=-1;
    }
private:
    bool check(int x, int y, string s, vector<string>& wordDict){
        string cur = s.substr(x-1, y-x+1);
        //cout<<x<<' '<<y<<' '<<cur<<endl;
        for(int i = 0; i < wordDict.size(); i++){
            if (wordDict[i].compare(cur)==0) {
                return true;
            }
        }
        return false;
    }
};
