class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length()==0) {
            return true;
        }
        int x = 0;
        int y = 0;
        while(y!=t.length()){
            if (s[x]==t[y]) {
                x++;
                if (x==s.length()) {
                    return true;
                }
            }
            y++;
        }
        return false;
    }
};
