最长公共子序列，最长公共子串。他们的区别在于当s[i]!=t[j]时候的处理，对于最长公共子序列，max(dp[i-1][j],dp[i][j-1]);对于最长公共子串，dp[i][j]=0。因为
当此时不相同时，子串中断。参考discuss中，从末尾开始找最少需要删除多少个字母。这也算是对于dp的灵活应用了。
/**
 * dp[i][j] = a[i] == b[j] ? dp[i + 1][j + 1] :
 *            min(1 + dp[i + 1][j],  // delete a[i] + mindist between a.substr(i+1), b.substr(j)
 *                1 + dp[i][j + 1])  // delete b[j] + mindist between a.substr(i), b.substr(j+1)
 */
