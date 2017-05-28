class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        if( A.size() < 3 ){
            return 0;
        }
        cout<<A.size()<<endl;
        for( int i = 1; i < A.size(); i++ ){
            int gap = A[i]-A[i-1];
            int len = 2;
            while( (i+1)<A.size() && (A[i+1]-A[i])==gap ){
                i++;
                len++;
            }
            res += cal(len);
        }
        return res;
    }
private:
    int cal(int x){
        if( x < 3 ){
            return 0;
        }
        return (x-1)*(x-2)/2;
    }
};
