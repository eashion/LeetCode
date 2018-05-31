```
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //wall = {{1},{1},{1}};
        map<int, int> mm;
        for(int i = 0; i < wall.size(); i++){
            mm[wall[i][0]]++;
            //cout<<wall[i][0]<<" ";
            for(int j = 1; j < wall[i].size(); j++){
                wall[i][j] += wall[i][j-1];
                mm[wall[i][j]]++;
                //cout<<wall[i][j]<<" ";
            }
            //cout<<endl;
        }
        int res = 0;
        int bound = wall[0].back();
        //cout<<"bount: "<<bound<<endl;
        for(auto iter = mm.begin(); iter != mm.end(); iter++){
            if (bound == iter->first) 
                continue;
            //cout<<iter->first<<endl;
            res = max(res, iter->second);
        }
        //cout<<"res: "<<res<<endl;
        return wall.size()-res;
    }
};
```
