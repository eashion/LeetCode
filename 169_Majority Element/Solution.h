class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int cnt = 1;
        for( int i = 1; i < nums.size(); i++ ){
            if( nums[i] != res ){
                cnt--;
            }
            else{
                cnt++;
            }
            if( cnt == 0 ){
                res = nums[i];
                cnt = 1;
            }
        }
        return res;
    }
};
