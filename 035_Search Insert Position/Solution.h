class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return findPos(nums,target,0,nums.size()-1);
    }
private:
    int findPos(vector<int> nums,int target,int left,int right){
        if( left > right ){
            return left;
        }
        int mid = (left+right)>>1;
        if( nums[mid] == target ){
            return mid;
        }
        else if( nums[mid] > target ){
            return findPos(nums,target,left,mid-1);
        }
        else{
            return findPos(nums,target,mid+1,right);
        }
    }
};
