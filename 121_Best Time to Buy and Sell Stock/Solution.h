题目123的简化版本，但是还是没想出来。题目123是买两支股票，并且有先后顺序，必须先卖第一支后买第二支。121可以使用dc解，log得到答案。O(n)的算法比较难想，
思路是先更新sell，也就是收益，这样保证了卖在买前面。买利用负数表示，就相当于借的钱越少越好。用buy+prices，相当于在当前价格卖的收益。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        for(int i = 0; i < prices.size(); i++){
            sell = max(sell, buy+prices[i]);
            buy = max(buy, -prices[i]);
        }
        return sell;
    }
};
