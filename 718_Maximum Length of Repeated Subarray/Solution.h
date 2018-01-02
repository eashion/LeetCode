class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if (m==0 || n==0) {
            return 0;
        }
        int res = 0;
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i]==B[j]) {
                    if (i==0 || j==0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1]+1;
                        res = max(res,dp[i][j]);
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
