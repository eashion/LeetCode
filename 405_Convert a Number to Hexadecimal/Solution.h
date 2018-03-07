class Solution {
char mm[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
public:
    string toHex(int num) {
        if (num>=0) {
            return transfer(num);
        } else {
            return transfer(0x100000000+num);
        }
    }
private:
    string transfer(long num){
        if (num==0) {
            return "0";
        }
        string res = "";
        while(num!=0){
            res += mm[num%16];
            num /= 16;
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
        return res;
    }
};
