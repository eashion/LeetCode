两种方法，一种是顺序遍历找下降沿，一种是二分。
class Solution {
public:
    /*int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        for(int i = 1; i < nums.size(); i++){
            if (nums[i]<nums[i-1]) {
                return i-1;
            }
        }
        return nums.size()-1;
    }*/
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1) {
            return 0;
        }
        int res = -1;
        doDevide(nums,0,nums.size()-1,res);
        return res;
    }
    void doDevide(vector<int> nums,int x,int y,int &res){
        if (res!=-1) {
            return ;
        }
        if (x>y) {
            return ;
        }
        if (x==y) {
            if (x!=0 && x!=nums.size()-1 && nums[x]>nums[x-1] && nums[x]>nums[x+1]) {
                res = x;
                return ;
            }
            if (x==0 && nums[x]>nums[x+1]) {
                res = x;
                return ;
            }
            if (x==nums.size()-1 && nums[x]>nums[x-1]) {
                res = x;
                return ;
            }
            return ;
        }
        int mid = (x+y)/2;
        doDevide(nums,x,mid,res);
        doDevide(nums,mid+1,y,res);
        return ;
    }
};
