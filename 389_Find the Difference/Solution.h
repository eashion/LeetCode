class Solution {
public:
    char findTheDifference(string s, string t) {
        int mm[30] = {0};
        for( int i = 0; i < s.length(); i++ ){
            mm[s[i]-'a']++;
        }
        for( int i = 0; i < t.length(); i++ ){
            mm[t[i]-'a']--;
        }
        for( int i = 0; i < 26; i++ ){
            if( mm[i] != 0 ){
                return char(i+'a');
            }
        }
    }
};
