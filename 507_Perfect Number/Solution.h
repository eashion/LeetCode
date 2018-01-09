class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 1;
        int limit = sqrt(num);
        for(int i = 2; i <= limit; i++){
            if (num%i == 0) {
                res += i;
                res += num/i;
            }
            if (res > num) {
                break;
            }
        }
        if (num == limit*limit) {
            res -= limit;
        }
        return res==num;
    }
};
