#include <vector>
#include <map>
using std::vector;
using std::map;

class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mm;
    vector<int> res;
    for( int i = 0; i < (int)nums.size(); i++ ){
        int tmp = nums[i];
        if( mm[target-tmp]!=0 && mm[target-tmp]!=i+1 ){
            res.push_back(mm[target-tmp]-1);
            res.push_back(i);
            break;
        }
        mm[tmp] = i+1;
    }
    return res;
}
};
