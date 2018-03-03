#dp, memorize the max number from 0 to i-2
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if (A.size()<2) {
            return true;
        }
        vector<int> dp(A.size()+2, -1);
        dp[0] = A[0];
        dp[1] = max(dp[0], A[1]);
        for (int i = 2; i < A.size(); i++) {
            dp[i] = max(dp[i-1],A[i]);
            if (A[i] < dp[i-2]) {
                return false;
            }
        }
        return true;
    }
};
