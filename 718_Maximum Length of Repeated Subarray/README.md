这道题目需要注意的是变长数组在java中支持，C++不支持。另外最长公共子序列不要求连续，最长公共子串要求连续。C++中变长数组的写法：vector<vector<int> > dp(m+1,vector<int>(n+1));
java变长数组写法：int dp[][] = new int[m + 1][n + 1];
