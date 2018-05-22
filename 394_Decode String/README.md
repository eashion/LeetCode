do it recursively.
```
class Solution {
public:
    string decodeString(string s) {
        //s = "3[a2[c]]";
        //s = "2[abc]3[cd]ef";
        string res = "";
        int num;
        string encode;
        for(int i = 0; i < s.length(); i++){
            if (s[i]>='1' && s[i]<='9') {
                num = getNum(i,s);
                encode = getEncode(i,s);
                //cout <<"encode1: "<<encode<<endl;
                encode = decodeString(encode);
                //cout <<"encode2: "<<encode<<endl;
                res += generate(num,encode);
                i--;
            } else {
                res += s[i];
            }
        }
        return res;
    }
private:
    int getNum(int& pos, string s){
        int num = 0;
        while(s[pos]>='0' && s[pos]<='9'){
            num = num*10 + s[pos]-'0';
            pos++;
        }
        return num;
    }
    string getEncode(int& pos, string s){
        string encode = "";
        pos++;
        int cnt = 1;
        while(cnt != 0){
            if (s[pos]==']') {
                cnt--;
            }
            if (s[pos]=='[') {
                cnt++;
            }
            encode += s[pos];
            pos++;
        }
        return encode.substr(0, encode.length()-1);
    }
    string generate(int times, string encode){
        string res = "";
        while(times--){
            res += encode;
        }
        return res;
    }
};
```
