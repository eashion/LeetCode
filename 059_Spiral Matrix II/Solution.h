class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int cnt = 1;
        int flag = 1;
        int px,py;
        px = 0;
        py = 0;
        while( cnt <= n*n ){
            if( cnt == 1 ){
                res[px][py] = cnt++;
                continue;
            }
            //right
            if( flag == 1 ){
                py += 1;
                if( py==n || res[px][py]!=0 ){
                    py -= 1;
                    px += 1;
                    flag = 2;
                }
            }
            //down
            else if( flag == 2 ){
                px += 1;
                if( px==n || res[px][py]!=0 ){
                    px -= 1;
                    py -= 1;
                    flag = 3;
                }
            }
            //left
            else if( flag == 3 ){
                py -= 1;
                if( py==-1 || res[px][py]!=0 ){
                    py += 1;
                    px -= 1;
                    flag = 4;
                }
            }
            //up
            else{
                px -= 1;
                if( px==-1 || res[px][py]!=0 ){
                    px += 1;
                    py += 1;
                    flag = 1;
                }
            }
            res[px][py] = cnt++;
        }
        return res;
    }
};
