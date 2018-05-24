The most direct way is BFS, it's obvious, but not efficient. DP will also work, but not efficient.
Use math to solve this problem. For a even number, the best way to achieve it is double. For an odd number, find the largest factor.
If the number is a prime number, then it can only achieved with plus 1.
```
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        while(n != 1){
            int m = findMin(n);
            res += m;
            n /= m;
        }
        return res;
    }
private:
    int findMin(int n){
        if (n%2 == 0) {
            return 2;
        }
        int m = sqrt(n);
        for(int i = 3; i <= m; i++){
            if (n%i == 0) {
                return i;
            }
        }
        return n;
    }
};
```
