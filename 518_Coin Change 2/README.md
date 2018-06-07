```
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //amount = 10;
        //coins = {10};
        vector<int> opt(amount+1, 0);
        opt[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j < amount+1; j++){
                opt[j] += opt[j-coins[i]];
            }
        }
        return opt[amount];
    }
};
```
