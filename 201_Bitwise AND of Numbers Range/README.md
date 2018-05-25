Think one more step. First, if n has more digits than n, then the answer is 0. And be care of the boundary case.
```
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //m = 0;
        //n = 1;
        //m = 2147483647;
        //n = 2147483647;
        if (m == 0) {
            return 0;
        }
        if (n/m >= 2) {
            return 0;
        }
        for(long i = long(m)+1; i <= n; i++){
            //cout<<i<<endl;
            m &= i;
        }
        return m;
    }
};
```
