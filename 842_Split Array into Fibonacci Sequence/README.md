easy but time-consuming.
```
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        //S = "1101111";
        //S = "0000";
        vector<int> res;
        if (S.length() < 3) {
            return res;
        }
        bool flag = true;
        for(int i = 0; i <= S.length()/2; i++){
            int num1 = getNum(0, i, S);
            res.push_back(num1);
            for(int j = i+1; j <= S.length()*2/3; j++){
                int num2 = getNum(i+1,j,S);
                res.push_back(num2);
                flag = fibonacci(num1, num2, j+1, S, res);
                if (flag == true) {
                    break;
                }
                res.pop_back();
            }
            if (flag == true) {
                break;
            }
            res.pop_back();
        }
        return res;
    }
private:
    bool fibonacci(int num1, int num2, int pos, string S, vector<int>& res){
        //cout<<"num1: "<<num1<<endl;
        //cout<<"num2: "<<num2<<endl;
        //cout<<"pos: "<<pos<<endl;
        long sum = (long)num1+num2;
        if (pos==S.length()) {
            return true;
        }
        bool flag;
        for(int i = pos; i < S.length(); i++){
            int num3 = getNum(pos,i,S);
            if (num3==sum) {
                res.push_back(num3);
                flag = fibonacci(num2, num3, i+1, S, res);
                if (flag == true) {
                    return true;
                } else {
                    res.pop_back();
                    return false;
                }
            } else if (num3 > sum) {
                return false;
            }
        }
        return false;
    }
    int getNum(int sta, int en, string S){
        int num = 0;
        if (S[sta]=='0' && sta!=en) {
            return -1;
        }
        for(int i = sta; i <= en; i++){
            num = num*10+S[i]-'0';
        }
        return num;
    }
};
```
