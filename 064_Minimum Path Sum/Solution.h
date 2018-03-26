class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //grid = {{1,2,5},{3,2,1}};
        vector<vector<int>> opt(grid.size(), vector<int>(grid[0].size(), 0));
        opt[0][0] = grid[0][0];
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (i==0) {
                    opt[i][j] = opt[i][j-1]+grid[i][j];
                } else if (j==0) {
                    opt[i][j] = opt[i-1][j]+grid[i][j];
                } else {
                    opt[i][j] = min(opt[i-1][j], opt[i][j-1])+grid[i][j];
                }
            }
        }
        /*
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                cout<<opt[i][j]<<' ';
            }
            cout<<endl;
        }*/
        return opt[grid.size()-1][grid[0].size()-1];
    }
};
