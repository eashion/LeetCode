/*class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if( row == 0 ){
            return ;
        }
        int column = board[0].size();
        if( column == 0 ){
            return ;
        }
        for( int i = 0; i < column; i++ ){
            if( board[0][i] == 'O' ){
                dfs(0,i,row,column,board);
            }
            if( board[row-1][i] == 'O' ){
                dfs(row-1,i,row,column,board);
            }
        }
        for( int i = 0; i < row; i++ ){
            if( board[i][0] == 'O' ){
                dfs(i,0,row,column,board);
            }
            if( board[i][column-1] == 'O' ){
                dfs(i,column-1,row,column,board);
            }
        }
        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < column; j++ ){
                if( board[i][j] == 'O' ){
                    board[i][j] = 'X';
                }
                else if( board[i][j] == 'A' ){
                    board[i][j] = 'O';
                }
            }
        }
        return ;
    }
private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int x,int y,int row,int column,vector<vector<char>>& board){
        queue<pair<int,int> > que;
        que.push(make_pair(x,y));
        board[x][y] = 'A';
        while( !que.empty() ){
            pair<int,int> tmp;
            tmp = que.front();
            que.pop();
            board[tmp.first][tmp.second] = 'A';
            for( int i = 0; i < 4; i++ ){
                int nx = tmp.first+dx[i];
                int ny = tmp.second+dy[i];
                if( nx<0 || ny<0 || nx==row || ny==column ){
                    continue;
                }
                if( board[nx][ny] == 'O' ){
                    que.push(make_pair(nx,ny));
                    board[nx][ny] = 'A';
                }
            }
        }
        return ;
    }
};*/
/*
class Solution {
public:
	void solve(vector<vector<char>>& board) {
        int i,j;
        int row=board.size();
        if(!row)
        	return;
        int col=board[0].size();

		for(i=0;i<row;i++){
			check(board,i,0,row,col);
			if(col>1)
				check(board,i,col-1,row,col);
		}
		for(j=1;j+1<col;j++){
			check(board,0,j,row,col);
			if(row>1)
				check(board,row-1,j,row,col);
		}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }
	void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			vec[i][j]='1';
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
	}
};*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if( row == 0 ){
            return ;
        }
        int column = board[0].size();
        for( int i = 0; i < column; i++ ){
            if( board[0][i] == 'O' ){
                dfs(0,i,row,column,board);
            }
            if( board[row-1][i] == 'O' ){
                dfs(row-1,i,row,column,board);
            }
        }
        for( int i = 0; i < row; i++ ){
            if( board[i][0] == 'O' ){
                dfs(i,0,row,column,board);
            }
            if( board[i][column-1] == 'O' ){
                dfs(i,column-1,row,column,board);
            }
        }
        for( int i = 0; i < row; i++ ){
            for( int j = 0; j < column; j++ ){
                if( board[i][j] == 'O' ){
                    board[i][j] = 'X';
                }
                else if( board[i][j] == 'A' ){
                    board[i][j] = 'O';
                }
            }
        }
        return ;
    }
private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    void dfs(int x,int y,int row,int column,vector<vector<char>>& board){
        board[x][y] = 'A';
        cout<<x<<' '<<y<<endl;
        for( int i = 0; i < 4; i++ ){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if( nx<0 || ny<0 || nx>=row || ny>=column ){
                continue;
            }
            else{
                //nx>=0 && ny>=0 && nx<row && ny<column &&
                if( board[nx][ny] == 'O' ){
                    dfs(nx,ny,row,column,board);
                }
            }
        }
        return ;
    }
};
