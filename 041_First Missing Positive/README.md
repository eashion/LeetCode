题目要求找到缺失的第一个整数，O(n)的时间复杂度，O(1)的空间复杂度。想到的第一个方法是优先队列，在写结构体的时候还遇到了一些麻烦。并且这个方法是不能满足O(1)时间复杂度的，时间上每次的插入
和弹出也比较耗时。参考discuss中的一种方法，将找到的满足条件的正整数放到数组中的正确位置，筛选出1~n之间缺少的第一个整数。
class Solution {
private:
//最小值优先
struct number{
    int x;
    number(int x){
        this->x = x;
    }
    bool operator < (const number &a) const {
        return x>a.x;
    }
};
public:
    int firstMissingPositive(vector<int>& nums) {
        priority_queue<number> que;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                number tmp(nums[i]);
                que.push(tmp);
            }
        }
        int res = 1;
        while(!que.empty()){
            int top = que.top().x;
            que.pop();
            if(top>res){
                return res;
            } else if (top==res) {
                res = top+1;
            }
        }
        return res;
    }
};
