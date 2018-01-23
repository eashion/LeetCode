class Solution {
public:
    bool judgeSquareSum(int c) {
        int range = sqrt(c);
        int right = range;
        int left = 0;
        while(right>=left){
            int t1 = pow(right,2);
            int t2 = c-t1;
            left = sqrt(t2);
            if (pow(left,2) == t2) {
                return true;
            }
            right--;
        }
        return false;
    }
};
