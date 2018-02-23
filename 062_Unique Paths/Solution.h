#trick在于n要从小开始消，小的比大的更容易满足
class Solution {
public:
    int uniquePaths(int m, int n) {
        long res = 1;
        if (m<n) {
            swap(m,n);
        }
        m--;
        n--;
        int pos = 2;
        for(int i = m+n; i > m; i--){
            res *= i;
            if (pos<=n && res%pos==0) {
                res /= pos;
                pos++;
            }
        }
        while (pos<=n) {
            res /= pos;
            pos++;
        }
        return res;
    }
};


class Solution {
    public:
        int uniquePaths(int m, int n) {
            int N = n + m - 2;// how much steps we need to do
            int k = m - 1; // number of steps that need to go down
            double res = 1;
            // here we calculate the total possible path number 
            // Combination(N, k) = n! / (k!(n - k)!)
            // reduce the numerator and denominator and get
            // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
            for (int i = 1; i <= k; i++)
                res = res * (N - k + i) / i;
            return (int)res;
        }
    };
