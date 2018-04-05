#需要利用双侧for循环计算出上下左右四个信息。。。而我想到的方法需要三层for循环
for (int i = 0; i < N; i++) {

    for (int j=0, l=0; j < N; j++) {
        // j is a column index, iterate from left to right
        // every time check how far left it can reach.
        // if grid[i][j] is 0, l needs to start over from 0 again, otherwise increment
        grid[i][j] = Math.min(grid[i][j], l = (grid[i][j] == 0 ? 0 : l + 1));
    }

    for (int k = N-1, r=0; k >= 0; k--) {
        // k is a column index, iterate from right to left
        // every time check how far right it can reach.
        // if grid[i][k] is 0, r needs to start over from 0 again, otherwise increment
        grid[i][k] = Math.min(grid[i][k], r = (grid[i][k] == 0 ? 0 : r + 1));
    }

    for (int j = 0, u=0; j < N; j++) {
        // j is a row index, iterate from top to bottom
        // every time check how far up it can reach.
        // if grid[j][i] is 0, u needs to start over from 0 again, otherwise increment
        grid[j][i] = Math.min(grid[j][i], u = (grid[j][i] == 0 ? 0 : u + 1));
    }

    for (int k = N-1, d=0; k >= 0; k--) {
        // k is a row index, iterate from bottom to top
        // every time check how far down it can reach.
        // if grid[k][i] is 0, d needs to start over from 0 again, otherwise increment
        grid[k][i] = Math.min(grid[k][i], d = (grid[k][i] == 0 ? 0 : d + 1));
    }

    // after four loops each time taking Math.min over the grid value itself
    // all grid values will eventually take the min of the 4 direcitons.
}
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        //N = 1;
        //mines = {{0,0}};
        vector<vector<int>> maze(N, vector<int>(N, N));
        for(int i = 0; i < mines.size(); i++){
            maze[mines[i][0]][mines[i][1]] = 0;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0, l = 0; j < N; j++){
                maze[i][j] = min(maze[i][j], l = (maze[i][j]==0?0:l+1));
            }
            for(int k = N-1, r = 0; k >= 0; k--){
                maze[i][k] = min(maze[i][k], r = (maze[i][k]==0?0:r+1));
            }
            for(int j = 0, u = 0; j < N; j++){
                maze[j][i] = min(maze[j][i], u = (maze[j][i]==0?0:u+1));
            }
            for(int k = N-1, d = 0; k >= 0; k--){
                maze[k][i] = min(maze[k][i], d = (maze[k][i]==0?0:d+1));
            }
        }
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                //cout<<maze[i][j]<<" ";
                res = max(res, maze[i][j]);
            }
            //cout<<endl;
        }
        return res;
    }
};
