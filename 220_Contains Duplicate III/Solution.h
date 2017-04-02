class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> lis;//自动有序
        for( int i = 0; i < nums.size(); i++ ){
            if( i > k ){
                lis.erase(nums[i-k-1]);
            }
            auto pos = lis.lower_bound((long)nums[i]-t);//nums[pos]>=nums[i]-t-->nums[pos]-nums[i]>=-t
            if( pos!=lis.end() && *pos-nums[i]<=t ){ //nums[pos]-nums[i]<=t-->|nums[pos]-nums[i]|<=t
                return true;
            }
            lis.insert((long)nums[i]);
        }
        return false;
    }
};
