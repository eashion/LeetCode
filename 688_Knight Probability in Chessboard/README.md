probability dp.
```
struct Node{
    int r,c;
    Node(){}
    Node(int r,int c){
        this->r = r;
        this->c = c;
    }
};
class Solution {
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
public:
    double knightProbability(int N, int K, int r, int c) {
        if (K==0) {
            return 1.0;
        }
        //N = 3;
        ///K = 3;
        //r = 0;
        //c = 0;
        vector<vector<double>> opt1(N, vector<double>(N, 0.0));
        vector<vector<double>> opt2(N, vector<double>(N, 0.0));
        opt1[r][c] = 1.0;
        queue<Node> que;
        double res = 0.0;
        double base = 1.0/8;
        que.push(Node(r,c));
        que.push(Node(-1, -1));
        while(!que.empty()){
            Node cur = que.front();
            que.pop();
            //cout<<"cur: "<<cur.r<<" "<<cur.c<<endl;
            if (cur.r==-1 && cur.c==-1) {
                copy(opt1, opt2);
                K--;
                //cout<<"K: "<<K<<endl;
                if (K==0 || que.empty()) {
                    break;
                }
                else {
                    que.push(Node(-1,-1));
                    continue;
                }
            }
            if (opt1[cur.r][cur.c] == -1) {
                continue;
            }
            for(int i = 0;i < 8; i++){
                int nr = cur.r+dr[i];
                int nc = cur.c+dc[i];
                if (nr>=0 && nr<N && nc>=0 && nc<N) {
                    //cout<<"in que: "<<nr<<" "<<nc<<endl;
                    opt2[nr][nc] += opt1[cur.r][cur.c]*base;
                    que.push(Node(nr,nc));
                }
            }
            opt1[cur.r][cur.c] = -1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                res += opt1[i][j];
            }
        }
        return res;
    }
private:
    void copy(vector<vector<double>>& opt1, vector<vector<double>>& opt2){
        for(int i = 0; i < opt1.size(); i++){
            for(int j = 0; j < opt1[i].size(); j++){
                opt1[i][j] = opt2[i][j];
                opt2[i][j] = 0;
            }
        }
        return ;
    }
};
```
