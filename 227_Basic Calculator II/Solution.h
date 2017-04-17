class Solution {
public:
    int calculate(string s){
        stack<int> sta;
        char ope = '+';
        int tmp = 0;
        for( int i = 0; i < s.length(); i++ ){
            if( isdigit(s[i]) ){
                tmp = tmp*10+s[i]-'0';
            }
            if( !isdigit(s[i]) && !isspace(s[i]) || i==s.length()-1 ){
                if( ope == '-' ){
                    sta.push(-tmp);
                }
                else if( ope == '+' ){
                    sta.push(tmp);
                }
                else{
                    int num = sta.top();
                    sta.pop();
                    if( ope == '*' ){
                        sta.push(num*tmp);
                    }
                    else{
                        sta.push(num/tmp);
                    }
                }
                ope = s[i];
                tmp = 0;
            }
        }
        int res = 0;
        while( !sta.empty() ){
            res += sta.top();
            sta.pop();
        }
        return res;
    }
};
