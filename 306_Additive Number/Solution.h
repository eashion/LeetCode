class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.length()<=2) {
            return false;
        }
        bool flag = false;
        for(int i = 1; i <= num.length()/2; i++){
            long num1 = findNum(num,0,i);
            if (num[0]=='0' && i>=2) {
                break;
            }
            for(int j = 1; j <= (num.length()-i)/2; j++){
                long num2 = findNum(num,i,j);
                if (num2==-1) {
                    return false;
                }
                if (num[i]=='0' && j>=2) {
                    break;
                }
                checkAdditive(num1,num2,i+j,flag,num);
                if (flag) {
                    return true;
                }
            }
        }
        return flag;
    }
private:
    long findNum(string num,int sta,int len){
        if (sta+len >= num.length()) {
            return -1;
        }
        string res = num.substr(sta,len);
        return stol(res);
    }
    void checkAdditive(long num1,long num2,int sta,bool &flag,string num){
        if (sta==num.length()) {
            flag = true;
            return ;
        }
        string res = to_string(num1+num2);
        if (sta+res.length() > num.length()) {
            flag = false;
            return ;
        }
        string target = num.substr(sta,res.length());
        if (res==target) {
            sta = sta+res.length();
            num1 = num2;
            num2 = stol(res);
            checkAdditive(num1,num2,sta,flag,num);
        } else {
            flag = false;
            return ;
        }
        return ;
    }
};
