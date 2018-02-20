class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1,nums2);
        }
        int m = nums1.size();
        int n = nums2.size();
        if (n==0) {
            return 0.0;
        }
        int imin = 0;
        int imax = m;
        int halflen = (m+n+1)/2;
        while(imin<=imax){
            int i = (imin+imax)/2;
            int j = halflen-i;
            if (i<m && nums2[j-1]>nums1[i]) {
                imin = i+1;
            } else if (i>0 && nums1[i-1]>nums2[j]) {
                imax = i-1;
            } else {
                int max_left;
                if (i==0) {
                    max_left = nums2[j-1];
                } else if (j==0) {
                    max_left = nums1[i-1];
                } else {
                    max_left = max(nums1[i-1], nums2[j-1]);
                }
                if ((m+n)%2 == 1) {
                    return max_left;
                }
                int min_right;
                if (i==m) {
                    min_right = nums2[j];
                } else if (j==n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums1[i], nums2[j]);
                }
                return (max_left+min_right)/2.0;
            }
        }
        return 0.0;
    }
};
