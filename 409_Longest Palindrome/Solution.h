class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        int num[200];
        int res = 0;
        bool flag = false;
        memset(num,0,sizeof(num));
        for( int i = 0; i < len; i++ ){
            int tmp = (int)s[i];
            num[s[i]]++;
        }
        for( int i = 0; i < 200; i++ ){
            if( num[i] == 0 ){
                continue;
            }
            if( num[i]%2 == 0 ){
                res += num[i]/2;
            }
            else{
                flag = true;
                res += (num[i]-1)/2;
            }
        }
        if( flag ){
            res = res*2+1;
        }
        else{
            res *= 2;
        }
        return res;
    }
};
