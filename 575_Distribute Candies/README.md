Read the statement clearly.
```
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        //candies = {1,1,2,3};
        double res = 0;
        if (candies.size()==0) {
            return (int)res;
        }
        map<int, int> mm;
        for(int i = 0; i < candies.size(); i++){
            mm[candies[i]]++;
        }
        return min(candies.size()/2, mm.size());
    }
};
```
