class MagicDictionary {
private:
    set<string> dic;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i = 0; i < dict.size(); i++){
            dic.insert(dict[i]);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto iter = dic.begin(); iter!=dic.end(); iter++){
            if (check(*iter, word)) {
                return true;
            }
        }
        return false;
    }
private:
    bool check(string item, string word){
        if ( item.length()!=word.length() ) {
            return false;
        }
        int cnt = 0;
        for(int i = 0; i < item.length(); i++){
            if (item[i]!=word[i]) {
                cnt++;
            }
            if (cnt==2) {
                return false;
            }
        }
        return cnt==1;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
