class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        //board = {"X  ","   ","  O"};
        int cx = 0;
        int co = 0;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].length(); j++){
                if (board[i][j]=='X') {
                    cx++;
                } else if (board[i][j]=='O') {
                    co++;
                }
            }
        }
        if (co>cx || cx>co+1) {
            return false;
        }
        //cout<<"level1"<<endl;
        if (board[0][0]==board[0][1] && board[0][1]==board[0][2]) {
            if (board[0][0]=='X' && co==cx) {
                return false;
            } else if (board[0][0]=='O' && co!=cx) {
                return false;
            }
        }
        if (board[1][0]==board[1][1] && board[1][1]==board[1][2]) {
            if (board[1][0]=='X' && co==cx) {
                return false;
            } else if (board[1][0]=='O' && co!=cx) {
                return false;
            }
        }
        if (board[2][0]==board[2][1] && board[2][1]==board[2][2]) {
            if (board[2][0]=='X' && co==cx) {
                return false;
            } else if (board[2][0]=='O' && co!=cx) {
                return false;
            }
        }
        //cout<<"level2"<<endl;
        if (board[0][0]==board[1][0] && board[1][0]==board[2][0]) {
            if (board[0][0]=='X' && co==cx) {
                return false;
            } else if (board[0][0]=='O' && co!=cx) {
                return false;
            }
        }
        if (board[0][1]==board[1][1] && board[1][1]==board[2][1]) {
            if (board[0][1]=='X' && co==cx) {
                return false;
            } else if (board[0][1]=='O' && co!=cx) {
                return false;
            }
        }
        if (board[0][2]==board[1][2] && board[1][2]==board[2][2]) {
            if (board[0][2]=='X' && co==cx) {
                return false;
            } else if (board[0][2]=='O' && co!=cx) {
                return false;
            }
        }
        //cout<<"level3"<<endl;
        if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
            if (board[0][0]=='X' && co==cx) {
                return false;
            } else if (board[0][0]=='O' && co!=cx) {
                return false;
            }
        }
        //cout<<board[0][0]<<board[1][1]<<board[2][2]<<endl;
        if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
            if (board[0][2]=='X' && co==cx) {
                return false;
            } else if (board[0][2]=='O' && co!=cx) {
                return false;
            }
        }
        //cout<<board[0][2]<<board[1][1]<<board[2][0]<<endl;
        //cout<<"level4"<<endl;
        return true;
    }
};
