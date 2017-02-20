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

class Solution {
private:
    int res,len,target; 
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
		int len = nums.size();
		for( int i = 0; i < len; i++ ){
			sum += nums[i];
		}
		if( sum<S || (sum+S)%2==1 ){
			return 0;
		}
		return subsetSum(nums,(S+sum)/2);
    }
	int subsetSum(vector<int> nums,int S){
		//注意此处的数组为变量的，由于数据量不确定，私以为这样做还是不太合适的
	        int dp[S+1]={0};
		dp[0] = 1;
		int len = nums.size();
		for( int i = 0; i < len; i++ ){
			for( int j = S; j >= nums[i]; j-- ){
				dp[j] += dp[j-nums[i]];
			} 
		}
		return dp[S];
	}
};
