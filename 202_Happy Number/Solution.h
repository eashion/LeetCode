class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mm;
        while(n != 1){
            if (mm.find(n)!=mm.end()) {
                return false;
            }
            mm[n] = true;
            n = cal(n);
        }
        return true;
    }
private:
    int cal(int num){
        int sum = 0;
        while(num != 0){
            sum += pow(num%10,2);
            num /= 10;
        }
        return sum;
    }
};
