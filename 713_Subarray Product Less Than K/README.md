At first I think this is a dp or segment tree. But the input size, the size of nums is at most 50000. Dp cannot handle this. While I am not 
familiar with segment tree. But one problem is I need to record the product and the sum of answers, also the problem of overlap.
Any way, I keep thinking record every small status. It's costing and useless. One big number can seperate following numbers from any status 
before the bid number. And according to the input size, O(n) or O(nlgn) time complexity is resonable.
While, I learn this from the discuss. It's really excellent. Instead of considering segments, we focus on each number. Number i, what's the 
resonable segments which is end at number i? We looking ahead from number i, possible answers are next to i. We don't need to know the exact
number of them, we just need to know their product and size. And for next state i+1, the situation is similar. Using a queue to maintain this
list is appropriate. Then the algorithm is clear.
```
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        queue<int> que;
        int product = 1;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            while(nums[i]*product>=k && que.size()){
                product /= que.front();
                que.pop();
            }
            if (product*nums[i] < k) {
                que.push(nums[i]);
                product *= nums[i];
            }
            res += que.size();
        }
        return res;
    }
};
```
