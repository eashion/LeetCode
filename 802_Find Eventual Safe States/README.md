Something like topology. Unlike indegree, in this problem we should focus on outDegree and record nodes enter in this terminal.
Find loop is another technology. But I can't figure out how to solve the case of joint loops.
```
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outDegree(graph.size(), 0);
        vector<vector<int>> inNodes(graph.size(), vector<int>());
        for(int i = 0; i < graph.size(); i++){
            outDegree[i] = graph[i].size();
            for(int j = 0; j < graph[i].size(); j++){
                inNodes[graph[i][j]].push_back(i);
            }
        }
        queue<int> terminal;
        for(int i = 0; i < graph.size(); i++){
            //printf("node: %d; outDegree: %d\n", i, outDegree[i]);
            if (outDegree[i]==0) {
                terminal.push(i);
            }
        }
        vector<int> res;
        while(!terminal.empty()){
            int cur = terminal.front();
            terminal.pop();
            res.push_back(cur);
            for(int i = 0; i < inNodes[cur].size(); i++){
                outDegree[inNodes[cur][i]]--;
                if (outDegree[inNodes[cur][i]] == 0) {
                    terminal.push(inNodes[cur][i]);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```
