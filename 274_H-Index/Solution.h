#这种题目像极了枚举答案，因为对于某个特定的解很好判断是否满足，且具有单调性。时间复杂度O(nlgn)，空间O(1)
#一个时间O(n)，空间O(n)的答案，利用bucket，因为答案不超过n，所以数组大小可知。但是如果答案范围不确定，还是二分枚举更robust一些
class Solution {
public:
    int hIndex(vector<int>& citations) {
        //citations = {3, 0, 6, 1, 5};
        vector<int> size(citations.size()+1,0);
        for(int i = 0; i < citations.size(); i++){
            if (citations[i]>=citations.size()) {
                size[citations.size()] += 1;
            } else {
                size[citations[i]] += 1;
            }
        }
        int cnt = 0;
        for(int i = citations.size(); i >= 0; i--){
            cnt += size[i];
            if (cnt>=i) {
                return i;
            }
        }
        return 0;
    }
};
