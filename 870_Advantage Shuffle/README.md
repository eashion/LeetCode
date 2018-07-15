During the comtest, I use another two list to record position and num, then sort the new array. Greedily choose numbers. Takes lots of time
 on this problem and the space complexity is not good. A O(N) map is enough, map is sorted, use map.upper_bound() to find if there is a larger 
 number in A. If not, choose the first element of map. use mm.erase to remove used elements.
 ```
 class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // A = {1,1,1,1,2};
        // B = {0,0,0,0,0};
        map<int, int> mm;
        int len = A.size();
        vector<int> res;
        for(int a : A){
            mm[a]++;
        }
        auto iter = mm.begin();
        for(int b : B){
            iter = mm.upper_bound(b);
            if (iter == mm.end()) {
                iter = mm.begin();
            }
            int cur = iter->first;
            res.push_back(cur);
            mm[cur]--;
            if (mm[cur] == 0) {
                mm.erase(iter);
            }
        }
        return res;
    }
};
 ```
