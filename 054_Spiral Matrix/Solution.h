class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size()==0 || matrix[0].size()==0) {
            return res;
        }
        int bound[4];
        bound[0] = matrix[0].size();
        bound[1] = matrix.size();
        bound[2] = -1;
        bound[3] = -1;
        int dirc = 0;
        int px = 0;
        int py = 0;
        int cnt = 0;
        while(true){
            res.push_back(matrix[px][py]);
            if (dirc == 0) {
                py++;
                if (py==bound[dirc]) {
                    bound[3] += 1;
                    dirc = 1;
                    py--;
                    px++;
                }
            } else if (dirc == 1) {
                px++;
                if (px==bound[dirc]) {
                    bound[0] -= 1;
                    dirc = 2;
                    px--;
                    py--;
                }
            } else if (dirc == 2) {
                py--;
                if (py==bound[dirc]) {
                    bound[1] -= 1;
                    dirc = 3;
                    py++;
                    px--;
                }
            } else if (dirc == 3) {
                px--;
                if (px==bound[dirc]) {
                    bound[2] += 1;
                    dirc = 0;
                    py++;
                    px++;
                }
            }
            cnt++;
            if (cnt==matrix.size()*matrix[0].size()) {
                break;
            }
        }
        return res;
    }
};
