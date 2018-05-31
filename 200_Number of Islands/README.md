```
class Solution {
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1') {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(int px, int py, vector<vector<char>>& grid){
        //cout<<px<<" "<<py<<endl;
        grid[px][py] = '0';
        for(int i = 0; i < 4; i++){
            int nx = px+dx[i];
            int ny = py+dy[i];
            if (nx>=0 && nx<grid.size() && ny>=0 && ny<grid[nx].size() && grid[nx][ny]=='1') {
                dfs(nx,ny,grid);
            }
        }
        return ;
    }
};
```
