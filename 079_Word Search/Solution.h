class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j]==word[0]) {
                    char tmp = board[i][j];
                    board[i][j] = '0';
                    dfs(board, i, j, word, 1, res);
                    board[i][j] = tmp;
                    if (res) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<char>>& board, int x, int y, string word, int pos, bool& res){
        if (res) {
            return ;
        }
        if (pos==word.length()) {
            res = true;
            return ;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx>=0 && nx<board.size() && ny>=0 && ny<board[x].size() && board[nx][ny]==word[pos]) {
                char tmp = board[nx][ny];
                board[nx][ny] = '0';
                dfs(board, nx, ny, word, pos+1, res);
                board[nx][ny] = tmp;
            }
        }
        return ;
    }
};
