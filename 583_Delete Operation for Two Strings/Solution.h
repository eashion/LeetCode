class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length()==0) {
            return word2.length();
        }
        if (word2.length()==0) {
            return word1.length();
        }
        int dp[505][505];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < word1.length(); i++){
            for(int j = 0; j < word2.length(); j++){
                if (word1[i]==word2[j]) {
                    if (i==0 || j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                } else {
                    if (i!=0 && j!=0) {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    } else if (i==0 && j!=0) {
                        dp[i][j] = dp[i][j-1];
                    } else if (i!=0 && j==0) {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        int res = word1.length()+word2.length()-2*dp[word1.length()-1][word2.length()-1];
        return res;
    }
};

class Solution {
public:
    int minDistance(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m || j < n)
                    dp[i][j] = i < m && j < n && a[i] == b[j] ?
                        dp[i + 1][j + 1] : 1 + min((i < m ? dp[i + 1][j] : INT_MAX), (j < n ? dp[i][j + 1] : INT_MAX));
            }
        }
        return dp[0][0];
    }
};
