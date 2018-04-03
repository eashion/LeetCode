class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++){
            if (i && check(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
private:
    bool check(int num){
        int devide = num;
        while(devide){
            if (devide%10 == 0) {
                return false;
            }
            if (num%(devide%10) != 0) {
                return false;
            }
            devide /= 10;
        }
        return true;
    }
};
