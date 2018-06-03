开始以为是bfs，结果超时。想不到好的剪枝。比赛结束后看别人代码知道是状态压缩dp。确实比较巧妙，时间复杂度也不高。
dp数组第一维表示已经访问的点，两种情况来更新未访问节点j。没有访问，访问过，然后用一个没有访问过的再更新。
dis数组用一般的Floyd去更新。
```
class Solution {
int MAX = 0x0ffffff;
int dp[1<<12+1][12];
int dis[12][12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        //cout<<MAX<<endl;
        memset(dp, 1, sizeof(dp));
        memset(dis, 1, sizeof(dis));
        for(int i = 0; i < n; i++){
            dis[i][i] = 0;
            dp[1<<i][i] = 0;
            for(int j = 0; j < graph[i].size(); j++){
                dis[i][graph[i][j]] = 1;
            }
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i = 1; i < (1<<n); i++){
            for(int j = 0; j < n; j++){
                if (i&(1<<j)==0) 
                    continue;
                for(int k = 0; k < n; k++){
                    if (i&(1<<k)==0) 
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k]+dis[k][j]);
                }
            }
        }
        int res = MAX;
        for(int i = 0; i < n; i++){
            res = min(res, dp[(1<<n)-1][i]);
        }
        return res;
    }
};
```
