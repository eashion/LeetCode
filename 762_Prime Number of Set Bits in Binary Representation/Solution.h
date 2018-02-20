class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<int> flag(25,0);
        flag[2] = 1;
        flag[3] = 1;
        flag[5] = 1;
        flag[7] = 1;
        flag[11] = 1;
        flag[13] = 1;
        flag[17] = 1;
        flag[19] = 1;
        flag[23] = 1;
        int res = 0;
        for(int i = L; i <= R; i++){
            int cnt = countNum(i);
            if (flag[cnt]==1) {
                res += 1;
            }
        }
        return res;
    }
    int countNum(int num){
        int cnt = 0;
        while(num){
            cnt += num%2;
            num = num/2;
        }
        return cnt;
    }
};


class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
