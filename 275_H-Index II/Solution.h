#既然已经有序了，那么二分查找就很方便去比较了。但是稍微废了点功夫，关于left和right的取值。要确定把合理的答案放到left还是right，这个要反映到初始值的设定。
#同时也和题目有关系，在这道题目中，如果mid满足，是要往left去贪心的，所以right保存合理解。注意自己测试一下特殊case。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size()==0) {
            return 0;
        }
        int left = -1;
        int right = citations.size();
        while(left<right-1){
            int mid = (left+right)/2;
            if (citations[mid]>=citations.size()-mid) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return citations.size()-right;
    }
};
