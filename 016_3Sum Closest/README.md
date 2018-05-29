The easiest way use 3 for loop. Time complexity is O(n^3). Remembered the question in interview. Find if there exist two number(or three number) which sum is
0. They are same question.
Two number. O(nlgn). Sort, and find two number from begining and end.
Three number. O(n^2+nlgn). Sort, fix one number, move two pointer from left and right.
One advantage of sort is we can find numbers in reasonable direction.
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //nums = {1,1,1,0};
        sort(nums.begin(), nums.end());
        int res = 0;
        int dis = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if (abs(sum-target)<dis) {
                    dis = abs(sum-target);
                    res = sum;
                }
                if (sum<target) {
                    j++;
                } else if (sum>target) {
                    k--;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
```
