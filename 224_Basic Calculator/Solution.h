#有些把问题想复杂了，因为只包含+-，所以可以对应看做数字前面的正负，括号中间顺序遍历得到答案。因为正负号不涉及到前面的值，如果是乘号或者除的话，就需要将
两个值都先处理，然后操作。碰到左括号，将已经计算出的结果存入栈，并且存下来左括号前面的符号。碰到右括号，把新算出来的结果与栈里面值相加。使用数字栈和符号
栈的方法用于解决后序表达式。
/*class Solution {
public:
    int calculate(string s) {
        stack<long> nums;
        stack<char> opes;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++){
            if (s[i] == ' ') {
                continue;
            }
            if (s[i]==')' || s[i]=='+' || s[i]=='-') {
                opes.push(s[i]);
            } else if (s[i] == '(') {
                cal(nums,opes);
            } else {
                scanNum(nums,i,s);
            }
        }
        cal(nums,opes);
        return nums.top();
    }
private:
    void cal(stack<long>& nums, stack<char>& opes){
        while(!opes.empty()){
            char cur = opes.top();
            opes.pop();
			if (cur==')') {
				break;
			}
            long num1 = nums.top();
            nums.pop();
            long num2 = nums.top();
            nums.pop();
            if (cur=='+') {
                num1 += num2;
                nums.push(num1);
            } else {
                num1 -= num2;
                nums.push(num1);
            }
        }
        return ;
    }
    void scanNum(stack<long>& nums, int& pos,string s){
        int num = 0;
        int time = 1;
        while(pos<s.length()){
            if (s[pos]=='(' || s[pos]=='+' || s[pos]=='-' || s[pos]==')' || s[pos]==' ') {
                pos--;
                break;
            }
            num = num+(s[pos]-'0')*time;
            time *= 10;
            pos++;
        }
        nums.push(num);
    }
};*/

class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};
