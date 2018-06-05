```
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        //a = "1+-1i";
        //b = "1+-1i";
        string res = "";
        int pos = 0;
        int a1 = getNum(a, pos);
        int a2 = getNum(a, pos);
        cout<<"a: "<<a1<<" "<<a2<<endl;
        pos = 0;
        int b1 = getNum(b, pos);
        int b2 = getNum(b, pos);
        cout<<"b: "<<b1<<" "<<b2<<endl;
        int r1 = a1*b1-a2*b2;
        int r2 = a2*b1+a1*b2;
        cout<<r1<<" "<<r2<<endl;
        res += r1<0?"-"+to_string(-r1):to_string(r1);
        res += "+";
        res += r2<0?"-"+to_string(-r2):to_string(r2);
        res += "i";
        return res;
    }
private:
    int getNum(string s, int& pos){
        int num = 0;
        int flag = 1;
        while(pos < s.length()){
            if (s[pos]=='+' || s[pos]=='i') {
                pos++;
                break;
            }
            if (s[pos]=='-') {
                flag = -1;
            } else {
                num = num*10+s[pos]-'0';
            }
            pos++;
        }
        return num*flag;
    }
};
```
