```
class Solution {
public:
    bool judgeCircle(string moves) {
        int px = 0;
        int py = 0;
        for(int i = 0; i < moves.length(); i++){
            if (moves[i] == 'L') {
                px -= 1;
            } else if (moves[i] == 'R') {
                px += 1;
            } else if (moves[i] == 'U') {
                py += 1;
            } else if (moves[i] == 'D') {
                py -= 1;
            }
        }
        if (px==0 && py==0) {
            return true;
        }
        return false;
    }
};
```
