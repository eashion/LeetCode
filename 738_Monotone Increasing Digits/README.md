```
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        //N = 1234;
        if (N < 10) {
            return N;
        }
        string num = to_string(N);
        string res = num.substr(0,1);
        bool flag = false;
        for(int i = 1; i < num.length(); i++){
            //cout<<i<<endl;
            if (flag == true) {
                res += "9";
                continue;
            }
            if (num[i] >= num[i-1]) {
                res += num[i];
            } else {
                int pos = i-1;
                backPro(pos,res);
                i = pos;
                flag = true;
            }
        }
        //cout<<res<<endl;
        return stoi(res);
    }
private:
    void backPro(int& pos, string& res){
        while(pos >= 0){
            if (res[pos]=='0' || (pos!=0 && res[pos]-res[pos-1]<1)) {
                pos--;
            } else {
                if (pos==0 && res[pos]=='1') {
                    res = "";
                } else {
                    res[pos] = char(res[pos]-1);
                    res = res.substr(0, pos+1);
                }
                break;
            }
        }
        //cout<<"res: "<<res<<endl;
        //cout<<"pos: "<<pos<<endl;
        return ;
    }
};
```
