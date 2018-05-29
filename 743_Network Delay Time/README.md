Shortest path without negative path.
```
class Solution {
private:
    int MAX = 10001;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        /*times = {{3,5,78},{2,1,1},{1,3,0},{4,3,59},{5,3,85},{5,2,22},{2,4,23},{1,4,43},{4,5,75},{5,1,15},{1,5,91},{4,1,16},{3,2,98},{3,4,22},{5,4,31},{1,2,0},{2,5,4},{4,2,51},{3,1,36},{2,3,59}};
        N = 5;
        K = 5;*/
        vector<vector<int>> path(N+1, vector<int>(N+1, MAX));
        for(int i = 0; i < times.size(); i++){
            int u,v,w;
            u = times[i][0];
            v = times[i][1];
            w = times[i][2];
            path[u][v] = min(path[u][v], w);
        }
        vector<int> update(N+1, 0);
        vector<int> dis(N+1, MAX);
        dis[K] = 0;
        update[K] = 1;
        while(true){
            int pos = -1;
            int next = MAX;
            for(int i = 1; i <= N; i++){
                if (update[i]==1 && (dis[i]<next)) {
                    pos = i;
                    next = dis[i];
                }
            }
            update[pos] = 0;
            //cout<<"cur pos: "<<pos<<endl;
            if (pos == -1) 
                break;
            for(int i = 1; i <= N; i++){
                if (i == pos) 
                    continue;
                if (dis[i] > path[pos][i]+dis[pos]) {
                    dis[i] = path[pos][i]+dis[pos];
                    update[i] = 1;
                    //cout<<"update: "<<i<<"; dis: "<<dis[i]<<endl;
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= N; i++){
            res = max(dis[i], res);
        }
        return res==MAX?-1:res;
    }
};
```
