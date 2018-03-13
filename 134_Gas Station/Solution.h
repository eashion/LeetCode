#I think this is a greedy algorithm. We can just use gas-cost to calculate.
#We always start from a positive position. If the number on the left is also positive, it means we have tried, but failed.
#Then without the left positive, the current poistive number will also fail.O(N^2)
#There is a O(N) algorithm. start with two pointer: sta and end, record the current sum.
#Every time, if sum is non-negative, then we go further end+1; while if sum is negative, we must start eailer, make start-1.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        for(int i = 0; i < gas.size(); i++){
            gas[i] -= cost[i];
        }
        for(int i = 0; i < gas.size(); i++){
            if (gas[i]<0) {
                continue;
            }
            if (i!=0 && gas[i-1]>0) {
                continue;
            }
            if (checkFit(gas,i) == true) {
                res = i;
                break;
            }
        }
        return res;
    }
private:
    int checkFit(vector<int>& gas,int pos){
        int save = gas[pos];
        int idx = (pos+1)%gas.size();
        while(idx!=pos){
            save += gas[idx];
            if (save<0) {
                return false;
            }
            idx = (idx+1)%gas.size();
        }
        return true;
    }
};


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1;
       int end = 0;
       int sum = gas[start] - cost[start];
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};
