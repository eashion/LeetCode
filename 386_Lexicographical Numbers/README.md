Solve it recursively is a good way, solve it with stack is another way, but not very efficient.
```
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //n = 101;
        vector<int> res;
        for(int i = 1; i < 10; i++){
            if(i <= n){
                searchAllNums(i, n, res);
            } else {
                break;
            }
        }
        return res;
    }
private:
    void searchAllNums(int cur, int bound, vector<int>& res){
        res.push_back(cur);
        //printf("cur: %d\n", cur);
        int left = cur*10;
        int right = (cur+1)*10;
        //printf("left: %d right:%d\n",left, right-1);
        for(int i = left; i < right; i++){
            if (i <= bound) {
                searchAllNums(i, bound, res);
            } else {
                break;
            }
        }
        return ;
    }
};
class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> rs;
        stack<int> stk;
        stk.push(1);
        while(!stk.empty())
        {
            int num = stk.top();
            rs.push_back(num);
            stk.pop();
            if(num + 1 <= n && num%10 < 9)
                stk.push(num + 1);
            if(10*num <= n)
                stk.push(10*num);
        }

        return rs;
    }
};
```
