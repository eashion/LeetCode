class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        bool res = true;
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int len = prerequisites.size();
        for( int i = 0; i < len; i++ ){
            int a = prerequisites[i].first;
            int b = prerequisites[i].second;
            graph[b].insert(a);
            indegree[a]++;
        }
        int cnt = numCourses;
        while( cnt-- ){
            int cur = -1;
            for( int i = 0; i < numCourses; i++ ){
                if( indegree[i] == 0 ){
                    indegree[i] = -1;
                    cur = i;
                    break;
                }
            }
            if( cur == -1 ){
                res = false;
                break;
            }
            len = graph[cur].size();
            for( int tmp : graph[cur] ){
                indegree[tmp]--;
            }
        }
        return res;
    }
};
