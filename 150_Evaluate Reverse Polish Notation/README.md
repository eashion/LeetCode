Easy and routine.
```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //tokens = {"4", "13", "5", "/", "+"};
        stack<int> sta;
        for(int i = 0; i < tokens.size(); i++){
            if (IfOperator(tokens[i])) {
                int num2 = sta.top();
                sta.pop();
                int num1 = sta.top();
                sta.pop();
                int res = operation(num1, num2, tokens[i]);
                sta.push(res);
            } else {
                int num = parseNumber(tokens[i]);
                sta.push(num);
            }
        }
        return sta.top();
    }
private:
    bool IfOperator(string ope){
        if (ope=="+" || ope=="-" || ope=="*" || ope=="/") {
            return true;
        }
        return false;
    }
    int operation(int num1, int num2, string ope){
        if (ope == "+") {
            return num1+num2;
        } else if (ope == "-") {
            return num1-num2;
        } else if (ope == "*") {
            return num1*num2;
        } else {
            return num1/num2;
        }
    }
    int parseNumber(string num){
        int flag = 1;
        int sta = 0;
        int res = 0;
        if (num[sta] == '-') {
            flag = -1;
            sta++;
        }
        for(int i = sta; i < num.length(); i++){
            res = res*10+(num[i]-'0');
        }
        return flag*res;
    }
};
```
