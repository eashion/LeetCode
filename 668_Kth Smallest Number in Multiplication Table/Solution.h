#这道题目还是很好的，和算法考试题目的相同点在于：上下有序，找第K小；区别在于每个数有规律可循，数据量大
#最开始想用传统的方法解，发现超时，多半是算法设计的问题
#discussion用binary search去做，确实符合binary search的特点，有序，方便判断。但是不好想出来。
#需要做一些转换，首先m*n的矩阵中只包含有理数，使用binary search会把无理数也考虑进来。
#但是没关系，最后左右区间还是会收敛到一个有理数的位置（第K小在矩阵中一定存在）
#判断某个值是否满足的时候，需要每一行都判断，利用乘法表的特点min(v/i, n)
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        //m = 9895;
        //n = 28405;
        //k = 100787757;
        //m = 2;
        //n = 3;
        //k = 6;
        int left = 0;
        int right = m*n;
        while(left<right-1){
            int mid = (left+right)/2;
            //cout<<mid<<endl;
            if (check(mid, m, n, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
private:
    bool check(int v, int m, int n, int k){
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            int tmp = min(v/i, n);
            cnt += tmp;
        }
        return cnt>=k;
    }
};
