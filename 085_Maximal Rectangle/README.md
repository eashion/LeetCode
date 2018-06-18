```
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<vector<int>> opt(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix[0].size(); i++){
            opt[0][i] = matrix[0][i]-'0';
        }
        int res = largestRectangleArea(opt[0]);
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] == '1') {
                    opt[i][j] = opt[i-1][j]+1;
                }
            }
            res = max(res, largestRectangleArea(opt[i]));
        }
        return res;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        //heights = {10,1,10};
        int res = 0;
        vector<int> insta;
        insta.push_back(0);
        heights.push_back(0);
        for(int i = 0; i < heights.size(); i++){
            while(insta.size()>0 && heights[i]<=heights[insta.back()]){
                int h = heights[insta.back()];
                insta.pop_back();
                int pos = insta.size()>0?insta.back():-1;
                int range = i-pos-1;
                res = max(res, range*h);
            }
            insta.push_back(i);
        }
        return res;
    }
};
```
