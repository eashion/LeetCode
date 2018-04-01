#two points for this question:
#1. Set is ordered by the less function, and iterator won't change after inset.https://blog.csdn.net/wallaceli1981/article/details/4723478
#2. This is a dp problem. every time we have three choice. *2,*3,*5 and they are overlapping.
class Solution {
public:
    int nthUglyNumber(int n) {
        //n = 1600;
        set<long> ugly;
        ugly.insert(1);
        int cnt = 1;
        auto iter = ugly.begin();
        while(cnt<n){
            ugly.insert(*iter*2);
            ugly.insert(*iter*3);
            ugly.insert(*iter*5);
            iter++;
            cnt++;
        }
        return *iter;
    }
};

struct Solution {
    int nthUglyNumber(int n) {
        vector <int> results (1,1);
        int i = 0, j = 0, k = 0;
        while (results.size() < n)
        {
            results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
            if (results.back() == results[i] * 2) ++i;
            if (results.back() == results[j] * 3) ++j;
            if (results.back() == results[k] * 5) ++k;
        }
        return results.back();
    }
};
