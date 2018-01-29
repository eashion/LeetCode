class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> sets;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            sets.insert(nums[i]);
            if (sets.size()==cnt) {
                return true;
            }
            cnt = sets.size();
        }
        return false;
    }
};
