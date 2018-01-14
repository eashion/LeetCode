class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) {
            return "0";
        }
        string res = "";
        bool flag = false;
        if (num<0) {
            num *= -1;
            flag = true;
        }
        while (num) {
            res += to_string(num%7);
            num /= 7;
        }
        if (flag) {
            res += "-";
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
