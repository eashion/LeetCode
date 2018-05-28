Seems like did before.
```
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        //A = {4,3,2,6};
        int sum = 0;
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            sum += A[i];
            res += i*A[i];
        }
        cout<<"sum: "<<sum<<endl;
        int pre = res;
        int pos = A.size()-1;
        for(int i = 1; i < A.size(); i++){
            pre = pre+sum-A.size()*A[pos--];
            //cout<<"pre: "<<pre<<endl;
            res = max(res, pre);
        }
        return res;
    }
};
```
