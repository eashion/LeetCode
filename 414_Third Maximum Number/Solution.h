#include <queue>
#include <vector>

using std::vector;
using std::greater;
using std::swap;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int lis[3];
        int cnt = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( cnt == 0 ){
                lis[cnt++] = nums[i];
            }
            else if( cnt == 3 ){
                if( nums[i] > lis[0] ){
                    lis[2] = lis[1];
                    lis[1] = lis[0];
                    lis[0] = nums[i];
                }
                else if( nums[i]>lis[1] && nums[i]!=lis[0] ){
                    lis[2] = lis[1];
                    lis[1] = nums[i];
                }
                else if( nums[i]>lis[2] && nums[i]!=lis[0] && nums[i]!=lis[1] ){
                    lis[2] = nums[i];
                }
            }
            else{
                if( cnt==1 && lis[0]!=nums[i] ){
                    lis[cnt++] = nums[i];
                    if( lis[0] < lis[1] ){
                        swap(lis[0],lis[1]);
                    }
                }
                else if( cnt==2 && lis[0]!=nums[i] && lis[1]!=nums[i] ){
                    lis[cnt++] = nums[i];
                    if( lis[0] < lis[2] ){
                        swap(lis[0],lis[2]);
                        swap(lis[1],lis[2]);
                    }
                    else if( lis[1] < lis[2] ){
                        swap(lis[1],lis[2]);
                    }
                }
            }
        }
        if( cnt == 3 ){
            return lis[2];
        }
        else{
            return lis[0];
        }
    }
};
