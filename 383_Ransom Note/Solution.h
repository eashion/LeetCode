class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //ransomNote = "aa";
        //magazine = "aba";
        vector<int> cnt(26, 0);
        for(int i = 0; i < ransomNote.length(); i++){
            cnt[ransomNote[i]-'a']++;
        }
        for(int i = 0; i < magazine.length(); i++){
            if (cnt[magazine[i]-'a']>=0) {
                cnt[magazine[i]-'a']--;
            }
        }
        for(int i = 0; i < 26; i++){
            if (cnt[i]>0) {
                return false;
            }
        }
        return true;
    }
};
