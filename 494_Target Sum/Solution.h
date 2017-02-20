class Solution {
private:
    int res,len,target; 
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        len = nums.size();
        res = 0;
        target = S;
        recur(0,0,0,nums);
        recur(0,0,1,nums);
        return res/2;
    }
    void recur(int pos,int sum,int type,vector<int>& nums){
        if( pos == len ){
            if( sum == target ){
                res++;
            }
            return ;
        }
        if( type == 0 ){
			sum += nums[pos];
            recur(pos+1,sum,0,nums);
            recur(pos+1,sum,1,nums);
        }
        else{
			sum -= nums[pos];
            recur(pos+1,sum,0,nums);
            recur(pos+1,sum,1,nums);
        }
        return ;
    }
};
