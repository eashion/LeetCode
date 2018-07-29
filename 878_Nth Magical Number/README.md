傻乎乎的妄想通过O(N)去解，10e9一定会爆掉。而且效率太低了。完全没必要把这个过程模拟出来。后来想到通过利用lcm，最小公倍数，可以知道每增加一个lcm，可以得到
(lcm/A + lcm/B - 1)个magic number。之后再模拟把剩下的添加上去。参考discuss有一个很巧妙的解法，binary search。很重要的一点，小于X的magic number=(X/A
 + X/B - X/lcm). 利用这个性质可以很快找到答案。
 ```
 struct Node{
    int num;
    int mod;
    Node(){}
    Node(int num, int mod){
        this->num = num;
        this->mod = mod;
    }
};
class Solution {
private:
    int MOD = 1e9+7;
public:
    int nthMagicalNumber(int N, int A, int B) {
        // N = 4, A = 2, B = 3;
        // N = 5, A = 2, B = 4;
        // N = 3, A = 6, B = 4;
        // N = 5, A = 6, B = 4;
        // N = 1e9;
        // A = 40000;
        // B = 40000;
        // N = 3, A = 3, B = 8;
        if (A == B) {
            return pow(A, N);
        }
        if(A > B){
            swap(A, B);
        }
        int sup = A*B/gcd(B,A);
        int cnt = (sup/A) + (sup/B) - 1;
        int res = pow(sup, N/cnt);
        N = N%cnt;
        int flag = -1;
        int a = A;
        int b = B;
        while(N--){
            if (A <= B) {
                A += a;
                flag = 0;
            } else {
                B += b;
                flag = 1;
            }
        }
        if (flag == 0) {
            res += A-a;
        } else {
            res += B-b;
        }
        return res%MOD;
    }
private:
    int gcd(int a, int b){
        if (a%b == 0) {
            return b;
        }
        return gcd(b, a%b);
    }
    int pow(int b, int p){
        return (((long long)b%MOD)*(p%MOD))%MOD;
    }
};
 ```
