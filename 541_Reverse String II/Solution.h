class Solution {
public:
    string reverseStr(string s, int k) {
        if(s==""){
            return s;
        }
        int n = s.length();
        int cnt = 2*k;
        auto iterS = s.begin();
        auto iterE = s.begin()+k;
        while(cnt<=n){
            reverse(iterS,iterE);
            cnt += 2*k;
            iterS = iterE+k;
            iterE = iterE+2*k;
        }
        cnt -= 2*k;
        if (n-cnt <= k) {
            reverse(iterS,s.end());
        } else {
            reverse(iterS,iterE);
        }
        return s;
    }
};

class Solution {
public:
    /**
     * 0            k           2k          3k
     * |-----------|-----------|-----------|---
     * +--reverse--+           +--reverse--+
     */
    string reverseStr(string s, int k) {
        for (int left = 0; left < s.size(); left += 2 * k) {
            for (int i = left, j = min(left + k - 1, (int)s.size() - 1); i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
