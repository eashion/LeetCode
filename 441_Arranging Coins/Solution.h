class Solution {
public:
    int arrangeCoins(int n) {
        if (n==0) {
            return 0;
        }
        int left = 1;
        int right = sqrt(INT_MAX)*2;
        while(right-left>1){
            long mid = (left+right)/2;
            long sum = mid*(mid+1)/2;
            if (n>=sum) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
