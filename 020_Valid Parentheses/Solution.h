class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        stack<char> sta;
        char tmp;
        for( int i = 0; i < s.length(); i++ ){
            if( s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                sta.push(s[i]);
            }
            else{
                if( sta.size() == 0 ){
                    res = false;
                    break;
                }
                tmp = sta.top();
                sta.pop();
                if( s[i]==')' && tmp!='(' ){
                    res = false;
                    break;
                }
                else if( s[i]==']' && tmp!='[' ){
                    res = false;
                    break;
                }
                else if( s[i]=='}' && tmp!='{' ){
                    res = false;
                    break;
                }
            }
        }
        if( sta.size() != 0 ){
            res = false;
        }
        return res;
    }
};
