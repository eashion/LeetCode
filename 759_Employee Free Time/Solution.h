/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> intervals;
        for(int i = 0; i < schedule.size(); i++){
            for(int j = 0; j < schedule[i].size(); j++){
                intervals.push_back(schedule[i][j]);
            }
        }
        vector<Interval> res;
        if (intervals.size()<=1) {
            return res;
        }
        sort(intervals.begin(),intervals.end(),mycompare);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1;i < intervals.size(); i++){
            if (intervals[i].start<=end) {
                end = max(intervals[i].end,end);
            } else {
                Interval tmp;
                tmp.start = end;
                tmp.end = intervals[i].start;
                res.push_back(tmp);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        return res;
    }
private:
    static bool mycompare(Interval x, Interval y) {
        if (x.start!=y.start) {
            return x.start<y.start;
        }
        return x.end<y.end;
    }
};
