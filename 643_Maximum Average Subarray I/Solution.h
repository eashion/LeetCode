class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            if (i<k) {
                cur += nums[i];
            } else {
                cur += nums[i]-nums[i-k];
            }
            if (i>=k-1) {
                maxSum = max(maxSum,cur);
            }
        }
        return maxSum*1.0/k;
    }
};
