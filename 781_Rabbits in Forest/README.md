```
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        //answers = {1,1,1,0,0};
        int res = 0;
        if (answers.size() == 0) {
            return res;
        }
        sort(answers.begin(), answers.end());
        int flag = -1;
        int cnt = 0;
        for(int i = 0; i < answers.size(); i++){
            if (answers[i]==flag-1 && cnt>0) {
                cnt--;
                continue;
            } else {
                flag = answers[i]+1;
                res += flag;
                cnt = flag-1;
            }
        }
        return res;
    }
};
```
