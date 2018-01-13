class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

class Solution {
public:
    int addDigits(int num) {
        return num==0||num%9!=0 ? num%9:9;
    }
};
