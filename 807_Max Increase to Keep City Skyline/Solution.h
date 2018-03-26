class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        vector<int> lislr(grid.size(), INT_MIN);
        vector<int> lisud(grid.size(), INT_MIN);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                lislr[j] = max(lislr[j], grid[i][j]);
                lisud[i] = max(lisud[i], grid[i][j]);
            }
        }
        /*for(int i = 0; i < grid.size(); i++){
            cout<<lislr[i]<<' ';
        }
        cout<<endl;
        for(int i = 0; i < grid.size(); i++){
            cout<<lisud[i]<<' ';
        }
        cout<<endl;*/
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                sum += min(lislr[j], lisud[i])-grid[i][j];
            }
        }
        return sum;
    }
};
