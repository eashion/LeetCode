WTF...
```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //bits = {1,1,1,0};
        //bits = {0,1,0};
        bool res = true;
        for(int i = 0; i < bits.size(); i++){
            if (bits[i]==1) {
                i++;
                res = false;
            } else {
                res = true;
            }
        }
        return res;
    }
};
 ```
