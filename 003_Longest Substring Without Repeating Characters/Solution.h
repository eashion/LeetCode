#include <cstring>
#include <cmath>

using std::string;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int sta = -1;
        int pos[200];
        int res = 0;
        memset(pos,-1,sizeof(pos));
        for( int i = 0; i < len; i++ ){
            int tmp = (int)s[i];
            if( pos[tmp] > sta ){
                sta = pos[tmp];
            }
            pos[tmp] = i;
            res = max(res,i-sta);
        }
        return res;
    }
};
