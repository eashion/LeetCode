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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),cmp);
        for( int i = 0; i < intervals.size(); i++ ){
            Interval tmp = intervals[i];
            while( (i+1)!=intervals.size() && intervals[i+1].start<=tmp.end ){
                tmp.end = max(tmp.end,intervals[i+1].end);
                i++;
            }
            res.push_back(tmp);
        }
        return res;
    }
private:
    static bool cmp(const Interval &a,const Interval &b){
        return a.start<b.start;
    }
};
