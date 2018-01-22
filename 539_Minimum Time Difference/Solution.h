class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        vector<int> time;
        for(int i = 0; i < timePoints.size(); i++){
            time.push_back(cal(timePoints[i]));
        }
        sort(time.begin(), time.end());
        for(int i = 0; i < time.size(); i++){
            if (i==time.size()-1) {
                res = min(res,time[0]+1440-time[i]);
            } else {
                res = min(res,time[i+1]-time[i]);
            }
        }
        return res;
    }
private:
    int cal(string time){
        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));
        return h*60+m;
    }
};
