easy problem.
```
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //rooms = {{1,3},{3,0,1},{2},{0}};
        map<int,int> mm;
        queue<int> que;
        que.push(0);
        int sum = 0;
        bool res = false;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            if (mm[cur] == 1) {
                continue;
            }
            sum++;
            mm[cur] = 1;
            if (sum == rooms.size()) {
                res = true;
                break;
            }
            for(int i = 0; i < rooms[cur].size(); i++){
                que.push(rooms[cur][i]);
            }
        }
        return res;
    }
};
```
