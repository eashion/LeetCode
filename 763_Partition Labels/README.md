```
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> right;
        for(int i = S.length()-1; i >= 0; i--){
            if (right.find(S[i]) == right.end()) {
                right[S[i]] = i;
            }
        }
        int lb = 0;
        int rb = -1;
        int pos = 0;
        vector<int> res;
        while(pos < S.length()){
            lb = pos;
            rb = right[S[pos]];
            pos++;
            while(pos <= rb){
                if (right[S[pos]] > rb) {
                    rb = right[S[pos]];
                }
                pos++;
            }
            res.push_back(rb-lb+1);
        }
        return res;
    }
};
```
