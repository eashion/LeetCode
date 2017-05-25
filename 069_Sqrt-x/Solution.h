class Solution {
public:
    int mySqrt(int x) {
        if( x == 1 ){
            return 1;
        }
        long long left = 0;
        long long right = x;
        long long mid = 0;
        while( left < right-1 ){
            mid = (left+right+1)>>1;
            long long res = mid*mid-x;
            if( res > 0 ){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        return left;
    }
};
