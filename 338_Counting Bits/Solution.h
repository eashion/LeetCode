class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        res[0] = 0;
        int cnt = 1;
        for(int i = 1; i <= num; i++){
            if (i==cnt) {
                res[i] = 1;
                cnt *= 2;
            } else {
                res[i] = res[i%(cnt/2)]+1;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};
