class Solution {
private:
    static bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int res = 0;
        sort(points.begin(), points.end(),cmp);
        for(int i = 0; i < points.size(); i++){
            res += 1;
            int pos = i+1;
            while (pos<points.size() && points[pos].first<=points[i].second) {
                pos++;
            }
            i = pos-1;
        }
        return res;
    }
};
