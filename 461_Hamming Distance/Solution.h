#位运算上面还是比较欠缺，^按位异或得到所有的1，n&n-1相当于/2
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0, n = x ^ y;
        while (n) {
            ++dist;
            n &= n - 1;
        }
        return dist;
    }
};

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while (x || y) {
            if (x%2 != y%2) {
                res += 1;
            }
            x /= 2;
            y /= 2;
        }
        return res;
    }
};
