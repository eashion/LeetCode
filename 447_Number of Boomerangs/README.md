Use map to reduce time complexity. Record number of points with same size. Think one more step.
```
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++){
            map<int, int> mm;
            for(int j = 0; j < points.size(); j++){
                if (j == i) 
                    continue;
                int dis = pow(points[i].first-points[j].first, 2)+pow(points[i].second-points[j].second, 2);
                mm[dis]++;
            }
            for(auto iter = mm.begin(); iter != mm.end(); iter++){
                res += iter->second*(iter->second-1);
            }
        }
        return res;
    }
};
```
