Spend lots of time on this problem. Had a wrong algorithm at first. In my algorithm, I focused on each number and thought to find it's next
larget number is a recurence process. While this algorithm worked, but not efficient. I think the time complexity should be O(NlgN). Spent 
lots of time on dealing with the index, TLE at the end. The right algorithm focus on each number as the larger number. Give it to numbers on
 the left of it. Use stack to store numbers haven't decided. Each number is garanteed push into stack once. Time complexity is O(N).
Next time don't see discuss directly. If you have a less optimal algorithm, spend time to optimize it. You will learn more from this problem.
```
 class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //findNums = {5,2,4};
        //nums = {5,1,2,3,4,6};
        //nums = {5,4,3,2,1,6,0};
        //nums = {1,1,1,1,1};
        //nums = {1,3,-1,2,0,-2,2};
        //nums = {0,2,0,2};
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> rank;
        for(int i = 0; i < 2*len; i++){
            int pos = i%len;
            while(!rank.empty() && nums[rank.top()]<nums[pos]){
                //cout<<"in"<<endl;
                res[rank.top()] = nums[pos];
                rank.pop();
            }
            if (i < len) {
                rank.push(i);
            }
        }
        return res;
    }
};
 ```
 
 ```
 class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //findNums = {5,2,4};
        //nums = {5,1,2,3,4,6};
        //nums = {5,4,3,2,1,6,0};
        //nums = {1,1,1,1,1};
        //nums = {1,3,-1,2,0,-2,2};
        //nums = {0,2,0,2};
        vector<int> res(nums.size(), -1);
        vector<int> mm(nums.size(), 0);
        if (nums.size()==0) {
            return res;
        }
        initialMap(nums, mm);
        for(int i = 0; i < nums.size(); i++){
            if (mm[i] == -1) {
                res[i] = -1;
            } else {
                res[i] = nums[mm[i]];
            }
        }
        return res;
    }
private:
    void initialMap(vector<int> nums, vector<int>& mm){
        int pos = 0;
        int maxNum = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                pos = i;
            }
        }
        mm[pos] = -1;
        //cout<<"pos: "<<pos<<endl;
        for(int i = pos-1; true;i--){
            if (i < 0) {
                i = nums.size()-1;
            }
            if (i == pos) {
                break;
            }
            mm[i] = findPos(nums[i], (i+1)%nums.size(), nums, mm);
        }
        return ;
    }
    int findPos(int cur, int pos, vector<int> nums, vector<int> mm){
        //cout<<cur<<" "<<pos<<endl;
        if (pos == -1) {
            return -1;
        }
        if (nums[pos] > cur) {
            return pos;
        } else {
            return findPos(cur, mm[pos], nums, mm);
        }
    }
};
 ```
