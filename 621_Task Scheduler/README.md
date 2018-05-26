I think too much for this problem....The algorithm is not dp, not dc, kind of a gready. I kept thinking solve this problem recursively.
I just didn't figure out the clear logic of this problem. We just need to concentrate on two factors. The numbers with maxlen and the maxlen.
There are two cases: 1. all the other characters can be fitted in the idle space. then the result is (n+1)*(maxlen-1)+cnt. Since all the other
characters is less than maxlen, if the idle space is enough, then we can find a solution. 2. if the idle space is not enough, the result is
tasks.size(). Because it's garanteed that we can find appropriate character to exchange to make the result satisfy constraints.
```
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        //n = 2;
        int maxNum = 0;
        int cnt = 0;
        map<char, int> mm;
        for(int i = 0; i < tasks.size(); i++){
            mm[tasks[i]] += 1;
            if (mm[tasks[i]] == maxNum) {
                cnt++;
            } else if (mm[tasks[i]] > maxNum) {
                maxNum = mm[tasks[i]];
                cnt = 1;
            }
        }
        return max((n+1)*(maxNum-1)+cnt, (int)tasks.size());
    }
};
```
