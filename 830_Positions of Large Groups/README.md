```
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        //S = "aaa";
        vector<vector<int>> res;
        if (S.length() < 3) {
            return res;
        }
        int cnt = 1;
        for(int i = 1; i < S.length(); i++){
            if (S[i] != S[i-1]) {
                if (cnt >= 3) {
                    vector<int> tmp;
                    tmp.push_back(i-cnt);
                    tmp.push_back(i-1);
                    res.push_back(tmp);
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if (cnt >= 3) {
            vector<int> tmp;
            tmp.push_back(S.length()-cnt);
            tmp.push_back(S.length()-1);
            res.push_back(tmp);
        }
        return res;
    }
};
```
