```
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        //widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        //S = "bbbcccdddaaa";
        vector<int> res;
        int num = 0;
        int cnt = 0;
        for(int i = 0; i < S.length(); i++){
            if (cnt+widths[S[i]-'a'] > 100) {
                cnt = widths[S[i]-'a'];
                num++;
            } else {
                cnt += widths[S[i]-'a'];
            }
        }
        res.push_back(num+1);
        res.push_back(cnt);
        return res;
    }
};
```
