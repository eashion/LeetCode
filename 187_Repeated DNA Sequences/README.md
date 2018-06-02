```
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mm;
        vector<string> res;
        //s = "AAAAAAAAAAAAA";
        if (s.length() < 10) {
            return res;
        }
        for(int i = 0; i < s.length()-9; i++){
            string tmp = s.substr(i, 10);
            //cout<<tmp<<endl;
            if (mm.find(tmp) != mm.end()) {
                if (mm[tmp] == 1) {
                    res.push_back(tmp);
                    mm[tmp] = 2;
                }
            } else {
                mm[tmp] = 1;
            }
        }
        return res;
    }
};
```
