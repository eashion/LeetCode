class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size()<3) {
            return false;
        }
        for(int i = nums.size()-1; i > 0; i--){
            cout<<nums[i]<<endl;
            if ( check(i-1,nums[i],nums) ){
                return true;
            }
        }
        return false;
    }
private:
    bool check(int pos, int num, vector<int> nums){
        bool f1 = false;
        bool f2 = false;
        while(pos>=0){
            if (nums[pos]>num) {
                f1 = true;
            } else if (nums[pos]<num) {
                if (f1) {
                    return true;
                }
                f2 = true;
            }
            pos--;
        }
        return false;
    }
};


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size()<3) {
            return false;
        }
        stack<int> sta;
        int s3 = NULL;
        for(int i = nums.size()-1; i >= 0; i--){
            if (s3!=NULL && s3>nums[i]) {
                return true;
            }
            while(!sta.empty()){
                int cur = sta.top();
                if (nums[i]>cur) {
                    s3 = s3==NULL?cur:max(s3,cur);
                    sta.pop();
                } else {
                    break;
                }
            }
            sta.push(nums[i]);
        }
        return false;
    }
};
