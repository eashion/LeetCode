At first I thought it was BFS. Although inefficient, but guaranteed to true. Problem is difficult to prunning. Failed at some case. MLE. So 
BFS is not the suitable algorithm. Then I found position of LR is special. RX->XR, XL->LX. So R only move to right, L only move to left. We 
can check if start is valid with O(n). Use cnt>0 to record the R currently we saved(since R can move right, we can save it), use cnt<0 record 
that how many L we need(L can move left, so we can borrow some L for now). And according to the relationship to check valid. BFS is really 
the first thought, but do need think one more step before coding. Not builtful code, but clear logic.
```
class Solution {
public:
    bool canTransform(string start, string end) {
        // start = "RXXLRXRXL", end = "XRLXXRRLX";
        // start = "XRXXLXLXXXXRXXXXLXXL";
        // end =   "XXRXLXXLXXRLXXXLXXXX";
        // start = "XXXRLLLXXXXXXXRLLLXX";
        // end = "XXXRLLLXXXXXXXRLLLXX";
        // start = "XXXXXLXXXX";
        // end = "LXXXXXXXXX";
        // start = "XXRXXLXXXX";
        // end = "XXXXRXXLXX";
        int len = start.length();
        if (len < 2) {
            return false;
        }
        int cnt = 0;//0 nothing, 1 save R, -1 need L
        for(int i = 0; i < len; i++){
            if (end[i] == start[i]) {
                if (end[i]=='L' && cnt>0) {
                    return false;
                } else if (end[i]=='R' && cnt<0) {
                    return false;
                }
                continue;
            }
            if (end[i] == 'R') {
                if (start[i] == 'L') {
                    return false;
                } else {
                    if (cnt <= 0) {
                        return false;
                    }
                    cnt--;
                }
            } else if (end[i] == 'L') {
                if (start[i] == 'R') {
                    return false;
                } else {
                    //cnt=0 is valid
                    if (cnt > 0) {
                        return false;
                    }
                    cnt--;
                }
            } else {
                if (start[i] == 'R') {
                    //cur=0 is valid, save R
                    if (cnt < 0) {
                        return false;
                    }
                    cnt++;
                } else if (start[i] == 'L') {
                    if (cnt >= 0) {
                        return false;
                    }
                    cnt++;
                }
            }
        }
        return cnt==0;
    }
};
```
