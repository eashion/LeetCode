I should think of devide and counquer early. That's obvious. And pay attention to mid*mid it could exceed the capacity of int.
```
class Solution {
public:
    bool isPerfectSquare(int num) {
        //num = 808201;
        int left = 1;
        int right = num+1;
        while(left < right){
            long mid = (left+right)/2;
            if (num > mid*mid) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return right*right==num;
    }
};
```
