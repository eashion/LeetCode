a^b add all different bits. a&b record all bits which all 1. <<1 represents add one bit.
https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
```
class Solution {
public:
    int getSum(int a, int b) {
        return b==0? a:getSum(a^b, (a&b)<<1);
    }
};
```
