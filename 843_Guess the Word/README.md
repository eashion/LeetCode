I don't understand why shuffle is necessary.
```
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        random_shuffle(wordlist.begin(), wordlist.end());
        int cnt = master.guess(wordlist[0]);
        if (cnt == 6) {
            return ;
        }
        vector<string> nextlvl;
        for(int i = 1; i < wordlist.size(); i++){
            if (cnt == checkMatch(wordlist[0], wordlist[i])) {
                nextlvl.push_back(wordlist[i]);
            }
        }
        dfs(1, nextlvl, master);
        return ;
    }
private:
    void dfs(int deep, vector<string> wordlist, Master& master){
        cout<<"deep: "<<deep<<endl;
        cout<<wordlist.size()<<endl;
        if (deep==11 || wordlist.size()==0) {
            return ;
        }
        random_shuffle(wordlist.begin(), wordlist.end());
        int cnt = master.guess(wordlist[0]);
        cout<<"guess: cnt: "<<cnt<<endl;
        if (cnt == 6) 
            return ;
        vector<string> nextlvl;
        for(int i = 1; i < wordlist.size(); i++){
            if (cnt == checkMatch(wordlist[0], wordlist[i])) {
                nextlvl.push_back(wordlist[i]);
            }
        }
        dfs(deep+1, nextlvl, master);
        return ;
    }
    int checkMatch(string a, string b){
        int cnt = 0;
        for(int i = 0; i < a.length(); i++){
            if (a[i]==b[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
```
