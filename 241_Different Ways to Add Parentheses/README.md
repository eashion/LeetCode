```
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //input = "2*3-4*5";
        vector<int> res;
        res = operate(input);
        return res;
    }
private:
    vector<int> operate(string input){
        vector<int> ans;
        int cur = isNumber(input);
        if (cur != -1) {
            ans.push_back(cur);
            return ans;
        }
        for(int i = 0; i < input.length(); i++){
            if (isOperator(input[i])) {
                vector<int> left = operate(input.substr(0,i));
                vector<int> right = operate(input.substr(i+1,input.length()-i-1));
                calculate(input[i],left,right,ans);
            }
        }
        return ans;
    }
    bool isOperator(char ope){
        if (ope=='+' || ope=='-' || ope=='*') {
            return true;
        }
        return false;
    }
    int isNumber(string num){
        int res = 0;
        for(int i = 0; i < num.length(); i++){
            int tmp = num[i]-'0';
            if (tmp>=0 && tmp<10) {
                res = res*10+tmp;
            } else {
                return -1;
            }
        }
        return res;
    }
    void calculate(char ope, vector<int> left, vector<int> right, vector<int>& ans){
        for(int i = 0; i < left.size(); i++){
            for(int j = 0; j < right.size(); j++){
                if (ope == '+') {
                    ans.push_back(left[i]+right[j]);
                } else if (ope == '-') {
                    ans.push_back(left[i]-right[j]);
                } else if (ope == '*') {
                    ans.push_back(left[i]*right[j]);
                }
            }
        }
        return ;
    }
};
```
