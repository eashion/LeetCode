class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool res = true;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if (board[i][j] != '.') {
                    checkRow(board,i,j,res);
                    checkCol(board,i,j,res);
                    checkGroup(board,i,j,res);
                    if (res==false) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
private:
    void checkRow(vector<vector<char>> board, int x, int y, bool& res){
        for(int i = 0; i < board.size(); i++){
            if (i!=y && board[x][i]==board[x][y]) {
                res = false;
                return ;
            }
        }
        return ;
    }
    void checkCol(vector<vector<char>> board, int x, int y, bool& res){
        for(int i = 0; i < board.size(); i++){
            if (i!=x && board[i][y]==board[x][y]) {
                res = false;
                return ;
            }
        }
        return ;
    }
    void checkGroup(vector<vector<char>> board, int x, int y, bool& res){
        int bx = (x/3+1)*3;
        int sy = (y/3)*3;
        for(int i = x; i < bx; i++){
            for(int j = sy; j < sy+3; j++){
                if (x==i && j==y) {
                    continue;
                }
                if (board[i][j]==board[x][y]) {
                    res = false;
                    return ;
                }
            }
        }
        return ;
    }
};
