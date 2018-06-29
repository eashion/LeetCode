看这个问题，第一思路是BFS，枚举所有可能的状态，但是状态转换思路有点复杂。第二思路是DFS，代码很简单，但是效率会低很多。第三种思路是dp，这个最开始没有想到。
```
opt[i][j] : if s[0~i-1] matches p[0~j-1]
if p[j-1] != '*':
  opt[i][j] = (s[i-1]==p[j-1] or p[j-1]=='.') && opt[i-1][j-1]
if p[j-1] == '*':
  opt[i][j] is true iff any of the following is true
  1. "x*" repeats 0 time and matches empty: j>1 && opt[i][j-2]
  2. "x*" x repeats 1 or more times: opt[i][j-1] or (j>0 && (s[i]==p[j-1] or p[j-1]=='.') && opt[i][j-1])
```
```
class Solution {
public:
    bool isMatch(string s, string p) {
        //s = "aab";
        //p = ".*b";
        // s = "aaa";
        // p = "ab*a*c*a";
        //opt[i][j] represents s[0~i] is matching with p[0~j]
        int slen = s.length();
        int plen = p.length();
        if (slen==0 && plen==0) {
            return true;
        }
        vector<vector<bool>> opt(slen+1, vector<bool>(plen+1, false));
        opt[0][0] = true;
        for(int j = 0; j < plen; j++){
            opt[0][j+1] = j>0 && p[j]=='*' && opt[0][j-1];
            // cout<<opt[0][j+1]<<" ";
        }
        // cout<<endl;
        for(int i = 0; i < slen; i++){
            for(int j = 0; j < plen; j++){
                if (p[j] == '*') {
                    opt[i+1][j+1] = (j>0 && opt[i+1][j-1]) || (opt[i+1][j]) || (j>0 && (s[i]==p[j-1] || p[j-1]=='.') && opt[i][j+1]);
                } else {
                    opt[i+1][j+1] = (s[i]==p[j] || p[j]=='.') && opt[i][j];
                }
                // cout<<opt[i+1][j+1]<<"-";
            }
            // cout<<endl;
        }
        return opt[slen][plen];
    }
};
```
