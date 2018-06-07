the key point is if N>4800, return 1.0
```
class Solution {
double dp[200][200];
public:
    double soupServings(int N) {
        if (N > 4800) 
            return 1.0;
        N = (N+24)/25;
        memset(dp, 0, sizeof(dp));
        return find(N,N);
    }
private:
    double find(int a, int b){
        if (a<=0 && b<=0)
            return 0.5;
        if (a <= 0) 
            return 1;
        if (b <= 0) 
            return 0;
        if (dp[a][b] != 0) 
            return dp[a][b];
        return dp[a][b] = 0.25*(find(a-4,b)+find(a-3,b-1)+find(a-2,b-2)+find(a-1,b-3));
    }
};
```
