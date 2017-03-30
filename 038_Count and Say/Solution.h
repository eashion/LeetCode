class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1;
        string cur = "1";
        while( cnt < n ){
            string tmp = "";
            int a = 1;
            for( int i = 1; i < cur.length(); i++ ){
                if( cur[i] == cur[i-1] ){
                    a++;
                }
                else{
                    tmp += to_string(a)+cur[i-1];
                    a = 1;
                }
            }
            tmp += to_string(a)+cur[cur.length()-1];
            cur = tmp;
            cnt++;
        }
        return cur;
    }
};
