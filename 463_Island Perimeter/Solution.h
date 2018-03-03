class Solution {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j);
                }
            }
        }
        return 0;
    }
private:
    int dfs(vector<vector<int>> &grid, int x, int y){
        grid[x][y] = 2;
        int cur = 0;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size() || grid[nx][ny]==0) {
                cur += 1;
            } else if (grid[nx][ny]==1){
                cur += dfs(grid,nx,ny);
            }
        }
        return cur;
    }
};
