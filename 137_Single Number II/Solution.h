class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        int mask = 0;
        //k=3,p=1;
        for(int i = 0; i < nums.size(); i++){
            x2 ^= x1&nums[i];
            x1 ^= nums[i];
            mask = ~(x1&x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};
