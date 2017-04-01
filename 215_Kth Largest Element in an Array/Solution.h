class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        qsort(nums,k,0,nums.size()-1);
        return nums[k-1];
    }
private:
    void qsort(vector<int>& nums,int k,int l,int r){
        if( l >= r ){
            return ;
        }
        int ll = l;
        int rr = r;
        int flag = nums[ll];
        while( ll < rr ){
            while( nums[rr]<=flag && rr>ll ){
                rr--;
            }
            if( rr > ll ){
                nums[ll] = nums[rr];
                ll++;
            }
            while( nums[ll]>flag && ll<rr ){
                ll++;
            }
            if( ll < rr ){
                nums[rr] = nums[ll];
                rr--;
            }
        }
        nums[ll] = flag;
        if( ll == k-1 ){
            return ;
        }
        if( ll > k-1 ){
            qsort(nums,k,l,ll-1);
        }
        else{
            qsort(nums,k,ll+1,r);
        }
    }
};
