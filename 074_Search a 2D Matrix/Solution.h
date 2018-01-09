class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0  || matrix[0].size()==0 || target<matrix[0][0]) {
            return false;
        }
        int pos = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while (pos<m && matrix[pos][0]<=target) {
            pos++;
        }
        if (pos==m&&target>matrix[pos-1][n-1]) {
            return false;
        }
        pos--;
        for(int i=0; i<n; i++){
            if (matrix[pos][i]==target) {
                return true;
            }
            if (matrix[pos][i]>target) {
                break;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r){
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};
