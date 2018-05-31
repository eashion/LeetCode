Greedy, same as the problem which want to do as many as jobs.
```
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        //intervals = {{1,2},{2,3},{1,3}};
        if (intervals.size() < 2) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int pos = 0;
        int res = 0;
        while(pos < intervals.size()){
            int next = pos+1;
            while(next<intervals.size() && intervals[next].start<intervals[pos].end){
                next++;
                res++;
            }
            pos = next;
        }
        return res;
    }
private:
    static bool cmp(Interval& a, Interval& b){
        if (a.end == b.end) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
};
```
