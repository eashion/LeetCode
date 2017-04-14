class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int tmp = 1;
        while( num ){
            if( num%2 == 0 ){
                res += tmp;
            }
            tmp*=2;
            num /= 2;
        }
        return res;
    }
};
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
