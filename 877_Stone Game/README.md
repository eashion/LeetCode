这道题目是做到过的，但是第二次看到没了思路。最开始我以为是博弈论的问题，有O(n)的巧妙解法。但是这个过程是交互的，不可能O(n)把所有的情况都涵盖。其实从一
开始就不应该把这道题目当做自己做过的，当做一道新题去思考。这道题目是可以看做从子问题而来的，关键是写出转换公式。后来想到把对手的最优结果作为负值，更新二维
opt数组，可以求解最后的答案。
另外一种想法是始终为true。参考：https://leetcode.com/problems/stone-game/discuss/154610/C++JavaPython-DP-or-Just-return-true
```
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // piles = {5,4,4,5};
        // piles = {7,7,12,16,41,48,41,48,11,9,34,2,44,30,27,12,11,39,31,8,23,11,47,25,15,23,4,17,11,50,16,50,38,34,48,27,16,24,22,48,50,10,26,27,9,43,13,42,46,24};
        int len = piles.size();
        vector<vector<int>> opt(len, vector<int>(len, 0));
        for(int i = 0; i < len; i++){
            opt[i][i] = -piles[i];
        }
        for(int i = len-1; i >= 0; i--){
            for(int j = i+1; j < len; j++){
                if((j-i)%2 == 1){
                    opt[i][j] = max(opt[i+1][j]+piles[i], opt[i][j-1]+piles[j]);
                } else {
                    opt[i][j] = max(opt[i+1][j]-piles[i], opt[i][j-1]-piles[j]);
                }
            }
        }
        return opt[0][len-1]>0;
    }
};
```
