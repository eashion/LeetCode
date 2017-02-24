class Solution {
public:
    int reverse(int x) {
        if( abs(x) < 10 ){
            return x;
        }
        int tmp;
        long long res = 0;
        bool flag = false;
        if( x < 0 ){
            flag = true;
            x = -x;
        }
        while( x > 0 ){
            tmp = x%10;
            x /= 10;
            if( res*10 > 2147483647 ){
                return 0;
            }
            res = res*10+tmp;
        }
        if( flag == true ){
            return -res;
        }
        return res;
    }
};
