We can solve this problem in three ways:
1. Use simple bfs.
we traversal all path from src to dst, use dist array to optimize, for each lvl, only use the shortest way to next lvl.
2. Use Dijkstra, or same as priority queue
only use the shortest to update update the other nodes. Once we achieve the dst, it' garanteed to be optimal.
3. Simple DP
record the lvl, use opt[i][k-1] update opt[j][i]
```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        const int INF = 1e9;
        K++;
        vector<vector<int>> ans(n, vector<int>(K+1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= K; j++)
            {
                ans[i][j] = INF;
            }
        }
        ans[src][0] = 0;
        for(int i = 1; i <= K; i++)
        {
            for(int j = 0; j < n; j++)   //To update ans[j][i](using i steps), we copy ans[j][i-1] first
                ans[j][i] = ans[j][i-1];
            for(const vector<int>& f: flights)
            {
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i-1] + f[2]);
            }
        }
        if(ans[dst][K] == INF) return -1;
        return ans[dst][K];
    }
};
```

```
struct Node{
    int pos;
    int expense;
    int lvl;
    Node(){}
    Node(int pos, int expense, int lvl){
        this->pos = pos;
        this->expense = expense;
        this->lvl = lvl;
    }
};
struct Dest{
    int pos;
    int expense;
    Dest(int pos, int expense){
        this->pos = pos;
        this->expense = expense;
    }
};
class Solution {
private:
    int maxn = 102;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // n = 3;
        // flights = {{0,1,100},{1,2,100},{0,2,500}};
        // src = 0, dst = 2, K = 0;
        // n = 4;
        // flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
        // src = 0;
        // dst = 3;
        // K = 1;
        queue<Node> que;
        que.push(Node(src,0,-1));
        vector<vector<Dest>> dist(n, vector<Dest>());
        int len = flights.size();
        for(int i = 0; i < len; i++){
            dist[flights[i][0]].push_back(Dest(flights[i][1],flights[i][2]));
        }
        int curlvl = 0;
        int res = INT_MAX;
        vector<vector<int>> lvlmap(n, vector<int>(K+1, INT_MAX));
        while(!que.empty()){
            Node node = que.front();
            que.pop();
            if (node.lvl > curlvl) {
                curlvl = node.lvl;
            }
            if (lvlmap[node.pos][node.lvl] < node.expense) {
                continue;
            }
            if (node.pos == dst) {
                res = min(res, node.expense);
            }
            for(int i = 0; i < dist[node.pos].size(); i++){
                int dst = dist[node.pos][i].pos;
                int weight = dist[node.pos][i].expense;
                int nxtlvl = node.lvl+1;
                if (lvlmap[dst][nxtlvl]>node.expense+weight && nxtlvl<=K) {
                    lvlmap[dst][nxtlvl] = node.expense+weight;
                    que.push(Node(dst, lvlmap[dst][nxtlvl], node.lvl+1));
                }
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};
```
