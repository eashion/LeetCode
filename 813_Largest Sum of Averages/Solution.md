#很好的一道题目,dp解决
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        //A = {1};
        //K = 1;
        double res = 0;
        if (A.size()==0) {
            return 0;
        }
        vector<int> sum(A.size(), 0);
        vector<vector<double>> opt(A.size(), vector<double>(K+1, 0));
        sum[0] = A[0];
        opt[0][1] = A[0];
        for(int i = 1; i < A.size(); i++){
            sum[i] = A[i]+=sum[i-1];
            opt[i][1] = 1.0*sum[i]/(i+1);
        }
        for(int i = 1; i < A.size(); i++){
            for(int k = 2; k <= K; k++){
                if (k>i+1) {
                    break;
                }
                for(int j = 0; j < i; j++){
                    opt[i][k] = max(opt[i][k], opt[j][k-1]+1.0*(sum[i]-sum[j])/(i-j));
                }
            }
        }
        /*
        for(int i = 0; i < A.size(); i++){
            for(int k = 1; k <= K; k++){
                cout<<opt[i][k]<<' ';
            }
            cout<<endl;
        }
        */
        return opt[A.size()-1][K];
    }
};
