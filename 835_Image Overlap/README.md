```
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res=0;
        if(A.empty())return res;
        int N=A.size(),M=A[0].size();
        for(int r=0;r<N;r++){
            for(int c=0;c<M;c++){//counter overlap '1' position start from (r,c)
                res=max(res,compare(A,B,r,c));
                res=max(res,compare(B,A,r,c));
            }
        }
        return res;
    }
private:
    int compare(vector<vector<int>>&a,vector<vector<int>>&b,int r,int c){ 
        int N=(int)a.size(),M=(int)a[0].size();
        int counter=0;
        for(int i=0;i<N&&i+r<N;i++)
            for(int j=0;j<M&&j+c<M;j++)
                if(1==a[i][j]&&1==b[i+r][j+c])
                    counter++;
        return counter;
    }
};
```
