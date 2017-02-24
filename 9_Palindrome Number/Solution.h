class Solution {
public:
    bool isPalindrome(int x) {
        bool res = true;
        if( x < 0 ){
            return false;
        }
        int len = 0;
        int num[20] = {0};
        while( x > 0 ){
            num[len++] = x%10;
            x /= 10;
        }
        for( int i = 0; i < len; i++ ){
            if( num[i] != num[len-1-i] ){
                res = false;
                break;
            }
        }
        return res;
    }
};
