class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mm = { {'I',1},
                             {'V',5},
                             {'X',10},
                             {'L',50},
                             {'C',100},
                             {'D',500},
                             {'M',1000} };
        int len = s.length();
        int sum = mm[s[len-1]];
        for( int i = len-2; i >= 0; i-- ){
            if( mm[s[i]] >= mm[s[i+1]] ){
                sum += mm[s[i]];
            }
            else{
                sum -= mm[s[i]];
            }
        }
        return sum;
    }
};
