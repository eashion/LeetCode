class Solution {
public:
    int integerBreak(int n) {
        //n = 10;
        vector<int> opt(n+1, 0);
        opt[1] = 1;
        for(int i = 2; i <= n; i++){
            opt[i] = 0;
            for(int k = 1; k <= i/2; k++){
                opt[i] = max(opt[i], max((i-k),opt[i-k])*max(k,opt[k]));
            }
            //cout<<i<<" "<<opt[i]<<endl;
        }
        return opt[n];
    }
};
