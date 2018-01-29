class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k==0 || nums.size()==0) {
            return false;
        }
        set<int> sets;
        for(int i = 0; i < nums.size(); i++){
            if( i > k ){
                sets.erase(nums[i-k-1]);
            }
            auto iter = sets.lower_bound(nums[i]);
            if (iter!=sets.end() && *iter==nums[i]) {
                return true;
            }
            sets.insert(nums[i]);
        }
        return false;
    }
};
