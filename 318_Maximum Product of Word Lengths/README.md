Try to have a clear understanding of your time complexity and find someway to optimize it. In this problem, O(N^2) is unavoidable, but every 
word only have lower characters, we can use pre operation to reduce the compare process. We only need 26 bits to record the different 
characters of each word, integer is enough. Remember to use () when compare the result of bit operation with integer.
```
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        int len = words.size();
        if (len < 2) {
            return res;
        }
        vector<int> record(len, 0);
        for(int i = 0; i < len; i++){
            int slen = words[i].length();
            for(int j = 0; j < slen; j++){
                record[i] |= 1<<(words[i][j]-'a');
            }
            // cout<<words[i]<<" "<<record[i]<<endl;
        }
        // printNum(record[0]);
        // printNum(record[0]^record[1]);
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                if ((record[i]&record[j]) == 0) {
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    res = max(res, (int)(words[i].length()*words[j].length()));
                }
            }
        }
        return res;
    }
private:
    void printNum(int num){
        while(num){
            cout<<num%2;
            num /= 2;
        }
        cout<<endl;
    }
};
```
