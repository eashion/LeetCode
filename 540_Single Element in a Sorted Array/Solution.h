class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if( nums.size() == 1 ){
            return nums[0];
        }
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i+1] == nums[i] ){
                i++;
            }
            else{
                return nums[i];
            }
        }
    }
};
