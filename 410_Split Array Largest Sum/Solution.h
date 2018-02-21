class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        long r = 0;
        for(int i = 0; i < nums.size(); i++){
            l = max(l, nums[i]);
            r += nums[i];
        }
        if (m==1)
            return r;
        if (m==nums.size())
            return l;
        while(l<r){
            int mid = (l+r)/2;
            /*
            cout<<l<<endl;
            cout<<r<<endl;
            cout<<mid<<endl;
            */
            if (checkSuit(nums, m, mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
private:
    bool checkSuit(vector<int> nums, int m, int target){
        int pos = 0;
        int cnt = 1;
        int sum = 0;
        while(pos<nums.size()){
            if (sum+nums[pos] > target) {
                sum = nums[pos];
                cnt++;
            } else {
                sum += nums[pos];
            }
            pos++;
        }
        return cnt<=m?true:false;
    }
};
