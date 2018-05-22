```
class Solution {
public:
    bool hasAlternatingBits(int n) {
        //n = 11;
        int flag = n%2;
        n /= 2;
        while(n){
            int base = n%2;
            if (flag == base) {
                return false;
            }
            flag = base;
            n /= 2;
        }
        return true;
    }
};
```
