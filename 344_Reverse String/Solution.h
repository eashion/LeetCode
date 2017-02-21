class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        string tmp;
        for( int i = len-1; i >= 0; i-- ){
            tmp += s[i];
        }
        return tmp;
    }
};

class Solution {
public:
    string reverseString(string s) {
        int sta = 0;
        int en = s.length()-1;
        while( sta < en ){
            swap(s[sta++],s[en--]);
        }
        return s;
    }
};
