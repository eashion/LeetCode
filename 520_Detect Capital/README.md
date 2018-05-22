```
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.length()<2) {
            return true;
        }
        int upper = 0;
        int lower = 0;
        for(int i = 0; i < word.size(); i++){
            if (word[i]>='a' && word[i]<='z') {
                lower++;
                if (upper > 1) {
                    return false;
                }
            } else {
                upper++;
                if (lower != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
