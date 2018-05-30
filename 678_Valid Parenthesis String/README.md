It's kind of greedy. We need to check from left and right. Because if the left+star is not enough, we can easily say it's invalid. Then if 
it can satisfy from either left or right. Then it's valid.
```
class Solution {
public:
    bool checkValidString(string s) {
        return checkFromLeft(s);// && checkFromRight(s);
    }
private:
    bool checkFromLeft(string s){
        if (s.length()==0) {
            return true;
        }
        int left = 0;
        int right = 0;
        int star = 0;
        for(int i = 0; i < s.length(); i++){
            if (s[i]=='(') {
                left++;
            } else if (s[i]==')') {
                right++;
            } else {
                star++;
            }
            if (right > left+star) {
                return false;
            }
        }
        if (right==left || (right-left)<=star) {
            return true;
        }
        return false;
    }
    bool checkFromRight(string s){
        if (s.length()==0) {
            return true;
        }
        int left = 0;
        int right = 0;
        int star = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if (s[i]==')') {
                left++;
            } else if (s[i]=='(') {
                right++;
            } else {
                star++;
            }
            if (right > left+star) {
                return false;
            }
        }
        if (right==left || (right-left)<=star) {
            return true;
        }
        return false;
    }
};
```
