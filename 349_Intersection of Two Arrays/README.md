find(vector) is not efficient.
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //nums1 = {1,2,2,1};
        //nums2 = {2,2};
        set<int> ss;
        map<int, int> mm;
        if (nums1.size()==0 || nums2.size()==0) 
            return vector<int>();
        if (nums1.size() < nums2.size()) 
            swap(nums1, nums2);
        for(int i = 0; i < nums1.size(); i++){
            mm[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++){
            //cout<<nums2[i]<<endl;
            if (mm[nums2[i]] == 1) {
                ss.insert(nums2[i]);
            }
        }
        return vector<int>(ss.begin(), ss.end());
    }
};
```
