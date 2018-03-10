#I think of a bad heuristic function.
struct State{
    vector<vector<int>> board;
    int step;
    int x,y;
    State(){}
    State(vector<vector<int>> board, int step, int x, int y){
        this->board = board;
        this->step = step;
        this->x = x;
        this->y = y;
    }
    int getValue() const {
        int cnt = 0;
        int pos = 1;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if (board[i][j]==pos) {
                    cnt += 1;
                }
                pos++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
		int dx[4] = {1,0,-1,0};
		int dy[4] = {0,1,0,-1};
        int x = 0;
        int y = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if (board[i][j]==0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        unordered_map<string, bool> mm;
        queue<State> que;
        State sta = State(board, 0, x, y);
        que.push(sta);
        int res = -1;
        mm[getStr(sta.board)] = true;
        while(!que.empty()){
            State cur = que.front();
            que.pop();
            if (cur.getValue()==5) {
                res = cur.step;
                break;
            }
            for(int i = 0; i < 4; i++){
                int nx = cur.x+dx[i];
                int ny = cur.y+dy[i];
                if (nx<0 || nx>1 || ny<0 || ny>2) {
                    continue;
                }
                vector<vector<int>> newboard(2, vector<int>(3, 0));
                newboard.assign(cur.board.begin(), cur.board.end());
                swap(newboard[nx][ny], newboard[cur.x][cur.y]);
				string tmp = getStr(newboard);
                if (mm[tmp]==true) {
                    continue;
                }
				mm[tmp] = true;
                State newstate = State(newboard, cur.step+1, nx, ny);
                que.push(newstate);
            }
        }
        return res;
    }
private:
    string getStr(vector<vector<int>> board){
        string res = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                res += to_string(board[i][j]);
            }
        }
        return res;
    }
};
