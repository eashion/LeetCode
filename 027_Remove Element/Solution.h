class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i] != val ){
                nums[i-cnt] = nums[i];
            }
            else{
                cnt++;
            }
        }
        return nums.size()-cnt;
    }
};
