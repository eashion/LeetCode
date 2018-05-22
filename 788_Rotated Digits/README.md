simple question. check function should as simple as possible.
```
class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
        for(int i = 1; i <= N; i++){
            if (check(i) == true) {
                res++;
                //cout<<i<<endl;
            }
        }
        return res;
    }
private:
    bool check(int num){
        int cnt = 0;
        while(num){
            int tmp = num%10;
            num /= 10;
            if (tmp==2 || tmp==5 || tmp==6 || tmp==9) {
                cnt++;
            } else if (tmp==3 || tmp==4 || tmp==7) {
                return false;
            }
        }
        return cnt!=0;
    }
};
```
