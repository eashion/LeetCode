Need to consider multi graph.
```
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //graph = {{1,3}, {0,2}, {1,3}, {0,2}, {5,6}, {4,6}, {4,5}};
        map<int, int> mm;
        bool res = true;
        for(int i = 0; i < graph.size(); i++){
            if (mm.find(i)!=mm.end() || graph[i].size()<2) 
                continue;
            mm[i] = 0;
            bfs(i, 1, res, graph, mm);
            if (res == false) 
                break;
        }
        return res;
    }
private:
    void bfs(int cur, int flag, bool& res, vector<vector<int>>& graph, map<int, int>& mm){
        if (res == false) {
            return ;
        }
        for(int i = 0; i < graph[cur].size(); i++){
            int pos = graph[cur][i];
            if (mm.find(pos) != mm.end()) {
                if (mm[pos] != flag) {
                    res = false;
                    return ;
                }
            } else {
                mm[pos] = flag;
                bfs(pos, (flag+1)%2, res, graph, mm);
            }
        }
        return ;
    }
};
```
