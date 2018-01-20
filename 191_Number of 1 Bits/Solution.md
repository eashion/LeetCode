int hammingWeight(uint32_t n) {
    int count = 0;
    
    while (n) {
        n &= (n - 1);
        count++;
    }
    
    return count;
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n){
            if (n%2==1) {
                res++;
            }
            n>>>1;
        }
        return res;
    }
};
