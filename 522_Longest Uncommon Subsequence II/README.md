sort according to the length of strs with descending order. The first str which is not a subsequence of the previous strs will be the answer.
```
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        //strs = {"aaa","aaa","aa"};
        map<string, int> mm;
        int res = 0;
        for(int i = 0; i < strs.size(); i++){
            mm[strs[i]] += 1;
        }
        for(int i = 0; i < strs.size(); i++){
            if (mm[strs[i]]==1 && checkMatch(strs[i], strs)) {
                res = max(res, (int)strs[i].length());
            }
        }
        return res==0?-1 : res;
    }
private:
    bool checkMatch(string cur, vector<string> strs){
        for(int i = 0; i < strs.size(); i++){
            if (cur==strs[i] || cur.length()>strs[i].length()) {
                continue;
            }
            int pos = 0;
            for(int j = 0; j < strs[i].length(); j++) {
                if (strs[i][j] == cur[pos]) {
                    pos++;
                    if (pos == cur.length()) {
                        break;
                    }
                }
            }
            if (pos == cur.length()) {
                return false;
            }
        }
        return true;
    }
};
```
