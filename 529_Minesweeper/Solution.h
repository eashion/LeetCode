class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //vector<vector<char>> res;
        int x,y;
        x = click[0];
        y = click[1];
        //cout<<x<<y<<endl;
        dfs(board,x,y);
        return board;
    }
private:
int dx[9]={1,0,-1,1,0,-1,1,0,-1};
int dy[9]={1,1,1,0,0,0,-1,-1,-1};
private:
    void dfs(vector<vector<char>>& board, int x,int y){
        if( board[x][y] == 'M' ){
            board[x][y] = 'X';
            return ;
        }
        else if( board[x][y] == 'E' ){
            int cnt = 0;
            board[x][y] = 'B';
            for( int i = 0; i < 9; i++ ){
                int nx = x+dx[i];
                int ny = y+dy[i];
                //cout<<nx<<' '<<ny<<endl;
                if( nx>=0 && nx<board.size() && ny>=0 && ny<board[nx].size() ){
                    if( board[nx][ny] == 'M' ){
                        cnt++;
                    }
                }
            }
            if( cnt != 0 ){
                board[x][y] = char(cnt+'0');
            }
            else{
                for( int i = 0; i < 9; i++ ){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if( nx>=0 && nx<board.size() && ny>=0 && ny<board[nx].size() ){
                        if( board[nx][ny] == 'E' ){
                            dfs(board,nx,ny);
                        }
                    }
                }
            }
        }
        return ;
    }
};
