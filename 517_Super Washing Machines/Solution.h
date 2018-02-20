class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int cnt = 0;
        for(int i = 0; i < machines.size(); i++){
            cnt += machines[i];
        }
        if (cnt%machines.size() != 0) {
            return -1;
        }
        int base = cnt/machines.size();
        int res = INT_MIN;
        int left = 0;
        for(int i = 0; i < machines.size(); i++){
            if (left > 0) {
                if (machines[i]+left>base) {
                    res = max(left+machines[i]-base, res);
                } else {
                    res = max(max(left,base-machines[i]-left), res);
                }
            } else {
                if (machines[i]+left<base) {
                    res = max(base-machines[i]-left, res);
                } else {
                    res = max(machines[i]-base, res);
                }
            }
            left += machines[i]-base;
            cout<<res<<endl;
        }
        return res;
    }
};
