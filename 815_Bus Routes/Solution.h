#这道题目还是想的太久了。最开始的想法有并查集，搜索，bfs。
#bfs是比较靠谱的，寻找最短变换次数。
#关键在于如何表示关系，是按照站，还是按照路线
#从数据量判断出按照路线，把公交站的关系转换为公交线路的关系还要花费一些脑筋，用了比较多的数据结构
#主要还是边写边犹豫，最后比赛刚结束A掉了。
#另外有几点是自己没想到的，1.每个公交线最多乘一次 2.leetcode不会难到哪里去
struct Node{
    int route;
    int cnt;
    Node(){}
    Node(int route, int cnt){
        this->route = route;
        this->cnt = cnt;
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int, int> mm;
        map<int, bool> sRoute;
        map<int, bool> tRoute;
        vector<int> tmp(routes.size(), 0);
        vector<vector<int>> edges(routes.size(), vector<int>());
        if (S==T) {
            return 0;
        }
        for(int i = 0; i < routes.size(); i++){
            int pos = i==0?-1:i;
            for(int j = 0; j < routes[i].size(); j++){
                if (routes[i][j]==S) {
                    sRoute[i] = true;
                }
                if (routes[i][j]==T) {
                    tRoute[i] = true;
                }
                if (mm[routes[i][j]]==0) {
                    mm[routes[i][j]] = pos;
                } else{
                    int tar = mm[routes[i][j]]==-1?0:mm[routes[i][j]];
                    edges[i].push_back(tar);
                    edges[tar].push_back(i);
                }
            }
        }
        queue<Node> que;
        for(int i = 0; i < routes.size(); i++){
            if (sRoute[i] == true) {
                que.push(Node(i,1));
                tmp[i] = 1;
            }
        }
        while(!que.empty()){
            Node cur = que.front();
            que.pop();
            if (tRoute[cur.route]==true) {
                return cur.cnt;
            }
            for(int i = 0; i < edges[cur.route].size(); i++){
                if (tmp[edges[cur.route][i]]==1) {
                    continue;
                }
                que.push(Node(edges[cur.route][i], cur.cnt+1));
                tmp[edges[cur.route][i]] = 1;
            }
        }
        return -1;
    }
};
