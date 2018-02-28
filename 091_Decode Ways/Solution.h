class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, 0);
        if (s.length()==0) {
            return 0;
        }
        if (s[0]=='0') {
            return 0;
        }
        if (s.length()==1) {
            return 1;
        }
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i-1]=='1' || (s[i-1]=='2'&&((s[i]-'0')<7))) {
                if (s[i]=='0') {
                    dp[i+1] = dp[i-1];
                } else {
                    dp[i+1] = dp[i]+dp[i-1];
                }
            } else {
                if (s[i]=='0') {
                    return 0;
                }
                dp[i+1] = dp[i];
            }
        }
        return dp[s.length()];
    }
};
