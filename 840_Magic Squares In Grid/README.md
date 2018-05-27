spend too much time on this simple problem.
```
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        /*grid = {{5,6,4,4,9,5,2},
                {8,3,9,9,8,1,3},
                {6,2,5,7,4,7,6},
                {8,6,5,3,5,1,6},
                {2,4,3,3,6,3,8},
                {3,8,2,6,2,5,1},
                {5,2,9,7,9,7,4}};*/
        if (grid.size()<3 || grid[0].size()<3) {
            return 0;
        }
        int res = 0;
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[i].size()-1; j++){
                if (checkLegal(i,j,grid)) {
                    res++;
                }
            }
        }
        return res;
    }
private:
    bool checkLegal(int x,int y, vector<vector<int>> grid) {
        if (grid[x][y] != 5) {
            return false;
        }
        //cout<<x<<" "<<y<<endl;
        vector<int> row(3, 0);
        vector<int> col(3, 0);
        vector<int> dig(2, 0);
        map<int, int> mm;
        for(int i = x-1; i <= x+1; i++){
            for(int j = y-1; j <= y+1; j++){
                mm[grid[i][j]] += 1;
                row[i-x+1] += grid[i][j];
                col[j-y+1] += grid[i][j];
            }
        }
        for(int i = 1; i < 10; i++){
            //cout<<"mm"<<i<<' '<<mm[i]<<endl;
            if (mm[i] != 1) {
                return false;
            }
        }
        dig[0] = grid[x-1][y-1] + grid[x][y] + grid[x+1][y+1];
        dig[1] = grid[x-1][y+1] + grid[x][y] + grid[x+1][y-1];
        /*for(int i = 0; i < 3; i++){
            cout<<"col"<<col[i]<<endl;
        }
        for(int i = 0; i < 3; i++){
            cout<<"row"<<row[i]<<endl;
        }*/
        if (col[0]!=15 || col[1]!=15 || col[2]!=15 || row[0]!=15 || row[1]!=15 || row[2]!=15 || dig[0]!=15 || dig[1]!=15) {
            return false;
        }
        return true;
    }
};
```
