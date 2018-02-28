#或者判断只要下一个大于上一个就加上差值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int res = 0;
        for(int i = 0; i < prices.size(); i++){
            if (sell<buy+prices[i]) {
                sell = buy+prices[i];
            } else {
                res += sell;
                sell = 0;
                buy = INT_MIN;
            }
            buy = max(buy, -prices[i]);
        }
        if (sell != 0) {
            res += sell;
        }
        return res;
    }
};
