Really smart algorithm. Solve the problem that words have different length. First reverse the entire string, set every words to the right
position, then reverse every words, change to the right order. At last clean duplicate space. Actually it's not really related to the main algorithm.
```
class Solution {
public:
    void reverseWords(string &s) {
        reverseAll(s);
        reverseEachWords(s);
        cleanSpace(s);
    }
private:
    void reverseAll(string& s){
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    void reverseEachWords(string& s){
        int pos = 0;
        while(pos < s.length()){
            if (s[pos] != ' ') {
                int p1 = pos;
                int p2 = pos;
                while(p2<s.length() && s[p2]!=' '){
                    p2++;
                }
                pos = p2;
                p2--;
                while(p1 < p2){
                    swap(s[p1], s[p2]);
                    p1++;
                    p2--;
                }
            }
            pos++;
        }
    }
    void cleanSpace(string& s){
        bool flag = true;
        for(auto iter = s.begin(); iter != s.end(); ){
            if (flag && *iter==' ') {
                iter = s.erase(iter);
            } else {
                if (*iter == ' ') {
                    flag = true;
                } else {
                    flag = false;
                }
                iter++;
            }
        }
        if (s[s.length()-1] == ' ') {
            s.erase(s.end()-1);
        }
    }
};
```
