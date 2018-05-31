a^b add all different bits. a&b record all bits which all 1. <<1 represents add one bit.
```
class Solution {
public:
    int getSum(int a, int b) {
        return b==0? a:getSum(a^b, (a&b)<<1);
    }
};
```
