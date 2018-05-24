My solution is so complicate and boring. First, sort all strings. Remember that sort is unstable. We should use stable_sort instead.
In discuss, I found a very neat version. Traverse every string. Do the same operation of each string with the licensePlate. Compare the
occurence of characters and occur times.
```
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        //licensePlate = "ad";
        //words = {"looks", "bad", "and", "show"};
        map<char, int> mm;
        operate(licensePlate, mm);
        stable_sort(words.begin(), words.end(), cmp);
        for(int i = 0; i < words.size(); i++){
            if (checkMatch(words[i], mm)) {
                return words[i];
            }
        }
        return "";
    }
private:
    void operate(string licensePlate, map<char, int>& mm){
        int base = 1;
        for(int i = 0; i < licensePlate.length(); i++){
            if (licensePlate[i]>='a' && licensePlate[i]<='z') {
                mm[licensePlate[i]]++;
            } else if (licensePlate[i]>='A' && licensePlate[i]<='Z') {
                char tmp = char(licensePlate[i]-'A'+'a');
                mm[tmp]++;
            }
        }
        return ;
    }
    static bool cmp(string a, string b){
        return a.length()<b.length();
    }
    bool checkMatch(string cur, map<char, int> mm){
        map<char, int> curSize;
        for(int i = 0; i < cur.length(); i++){
            if (mm.find(cur[i]) != mm.end()) {
                curSize[cur[i]]++;
            }
        }
        for(auto iter = mm.begin(); iter != mm.end(); iter++){
            if (iter->second > curSize[iter->first]) {
                return false;
            }
        }
        return true;
    }
};
```
