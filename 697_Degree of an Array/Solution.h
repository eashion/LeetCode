#思路是先找到最大的degree，之后去找最小的区间。map实现，我的代码中有两个地方可以改进。
#1. degree的map不需要排序，O(n)遍历后找到最大的degree
#2. 因为本身同一个元素的位置已经存有信息，可以把两个map转为将所有相同的值得坐标到vector中
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //nums = {1, 1};
        if (nums.size()<2) {
            return nums.size();
        }
        unordered_map<int, int> cnt;
        unordered_map<int, int> leftbound;
        unordered_map<int, int> rightbound;
        for(int i = 0; i < nums.size(); i++){
            if (cnt[nums[i]]==0) {
                cnt[nums[i]] = 1;
                leftbound[nums[i]] = i;
                rightbound[nums[i]] = i;
            } else {
                cnt[nums[i]] += 1;
                rightbound[nums[i]] = i;
            }
        }
        vector<pair<int, int>> lis;
        for(auto iter = cnt.begin(); iter!=cnt.end(); iter++){
            lis.push_back(make_pair(iter->first, iter->second));
        }
        sort(lis.begin(), lis.end(), [](const pair<int, int> &x, const pair<int, int> &y) -> int {
            return x.second > y.second;
        });
        //for(auto iter = lis.begin(); iter != lis.end(); iter++){
        //    cout<<iter->first<<"a"<<iter->second<<endl;
        //}
        int res = INT_MAX;
        int degree = lis[0].second;
        for(auto iter = lis.begin(); iter != lis.end(); iter++){
            if (iter->second==degree) {
                //cout<<rightbound[iter->first]<<" "<<leftbound[iter->first];
                res = min(rightbound[iter->first]-leftbound[iter->first]+1, res);
            } else {
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        int degree=0;
        for(auto it=mp.begin();it!=mp.end();it++) degree=max(degree,int(it->second.size()));
        int shortest=nums.size();
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second.size()==degree)
            {
                shortest=min(shortest,it->second.back()-it->second[0]+1);
            }
        }
        return shortest;
    }
};

##
