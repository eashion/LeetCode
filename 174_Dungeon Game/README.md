最开始把这道题的思路想成了dfs，结果超时，剪枝也没有效果。参考discuss之后发现是dp，只需要n^2的时间复杂度。公主和王子的题目之前做过，都是找路径的，使用
DFS解决。但是这道题目并不限制路径，一定能走到，关键在于最小代价是多少，和路径没多大关系。只要保证到达公主之前不死就可以了。所以我们可以从终点出发，求出
每个点需要补充的最小值，就能够得到最终的答案。另外dp还可以优化为一维的或利用原数组存储。
