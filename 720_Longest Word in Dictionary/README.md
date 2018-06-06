be careful about the logic of cmp function. Transfer to true false according to your logic.
```
class Solution {
public:
    string longestWord(vector<string>& words) {
        //words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
        //words = {"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
        map<string, int> mm;
        for(int i = 0; i < words.size(); i++){
            mm[words[i]] = 1;
        }
        string res = "";
        sort(words.begin(), words.end(), cmp);
        //cout<<"finish!"<<endl;
        for(int i = 0; i < words.size(); i++){
            if (checkMatch(words[i],mm) == true) {
                res = words[i];
                break;
            }
        }
        return res;
    }
private:
    bool checkMatch(string cur, map<string, int> mm){
        for(int i = cur.length()-1; i >= 1; i--){
            string tmp = cur.substr(0, i);
            if (mm[tmp] == 0) {
                return false;
            }
        }
        return true;
    }
    static bool cmp(string& a, string& b){
        if (a.length() == b.length()) {
            return a.compare(b) < 0;
        }
        return a.length() > b.length();
    }
};
```
