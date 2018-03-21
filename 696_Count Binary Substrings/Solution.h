#看到一道题目先想用什么样的算法写，之后想能最优使用什么样的时间复杂度解决，错误的算法思路可能会导致时间复杂度高一个量级，应该对时间复杂度敏感
class Solution {
public:
    int countBinarySubstrings(string s) {
        //s = "10101";
        int cnt = 0;
        int pre = 0;
        int cur = 1;
        char flag = s[0];
        for(int i = 1; i < s.length(); i++){
            if (s[i]!=flag) {
                cnt += min(pre, cur);
                pre = cur;
                cur = 1;
                flag = s[i];
            } else {
                cur++;
            }
        }
        cnt += min(pre,cur);
        return cnt;
    }
};
