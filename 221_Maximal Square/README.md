It's similar to maximal rectangle. But different approach. In maximal rectangle, we can project to skyline. And since we want the space of 
rectangle. We can solve it in O(n^2). But for square, it need O(n^3). Another approch is dp. dp[i][j] represents the length of 1 in right hand
side.
```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) {
            return 0;
        }
        int res = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> deep(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++){
            deep[n-1][i] = matrix[n-1][i]=='0'?0:1;
            res = max(res, deep[n-1][i]*deep[n-1][i]);
        }
        for(int i = 0; i < n; i++){
            deep[i][m-1] = matrix[i][m-1]=='0'?0:1;
            res = max(res, deep[i][m-1]*deep[i][m-1]);
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                if (matrix[i][j]=='1' && matrix[i+1][j]=='1' && matrix[i][j+1]=='1' && matrix[i+1][j+1]=='1') {
                    deep[i][j] = min(deep[i+1][j], min(deep[i+1][j+1], deep[i][j+1]))+1;
                } else {
                    deep[i][j] = matrix[i][j]-'0';
                }
                res = max(res, deep[i][j]*deep[i][j]);
            }
        }
        return res;
    }
};
```
```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) {
            return 0;
        }
        vector<vector<int>> deep(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int j = 0; j < matrix[0].size(); j++){
            deep[0][j] = matrix[0][j]-'0';
            //cout<<deep[0][j]<<' ';
        }
        //cout<<endl;
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == '1') {
                    deep[i][j] = deep[i-1][j]+1;
                }
                //cout<<deep[i][j]<<' ';
            }
            //cout<<endl;
        }
        int res = 0;
        for(int i = 0; i < deep.size(); i++){
            for(int k = 1; k <= deep[i].size(); k++){
                int cnt = 0;
                for(int j = 0; j < deep[i].size(); j++){
                    if (deep[i][j] >= k) {
                        cnt++;
                    } else {
                        cnt = 0;
                    }
                    if (cnt==k) {
                        res = max(k*k, res);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
```
