Couldn't see the relationship between this problem with the previous one. Just try to figure out the right algorithm. The Key point is find
which digits to swap. And after swap, the following digits should sort in increasing order.
```
class Solution {
public:
    int nextGreaterElement(int n) {
        //n = 987654321;
        //n = 1999999999;
        //n = 230241;
        //n = 12443322;
        int pre = n;
        vector<int> num;
        for(long i = n; i > 0; i /= 10){
            if (num.empty() || i%10>=num.back()) {
                num.push_back(i%10);
            } else {
                auto iter = lower_bound(num.begin(), num.end(), i%10+1);
                int tmp = *iter;
                *iter = i%10;
                i = (i/10)*10+tmp;
                sort(num.begin(), num.end());
                for(int t = 0; t < num.size(); t++){
                    i = i*10+num[t];
                }
                return i>INT_MAX?-1:i;
            }
        }
        return -1;
    }
};
```
