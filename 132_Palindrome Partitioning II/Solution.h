class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if (len<=1) {
            return 0;
        }
        vector<int> cnt(len+1,0);
        //前i个元素最多分多少
        for(int i = 0; i <= len; i++){
            cnt[i] = i-1;
        }
        for(int i = 0; i < len; i++){
            //odd
            for(int j = 0; i-j>=0 && i+j<len && s[i-j]==s[i+j]; j++){
                cnt[i+j+1] = min(cnt[i+j+1],cnt[i-j]+1);
            }
            //even
            for(int j = 1; i-j+1>=0 && i+j<len && s[i-j+1]==s[i+j]; j++){
                cnt[i+j+1] = min(cnt[i+j+1],cnt[i-j+1]+1);
            }
        }
        return cnt[len];
    }
    /*int minCut(string s) {
        int res = INT_MAX;
        if (s.length()<=1) {
            return 0;
        }
        findMiddle(0,s,0,res);
        return res;
    }
private:
    void findMiddle(int sta,string s,int cur,int &res){
        if (sta==s.length()) {
            res = min(cur-1,res);
            return ;
        }
        if (cur-1>=res) {
            return ;
        }
        for (int i = s.length()-sta; i >= 1; i--) {
            if (checkPalindrome(sta,i,s)) {
                findMiddle(sta+i,s,cur+1,res);
            }
        }
    }
    bool checkPalindrome(int sta,int len,string s){
        int en = sta+len-1;
        while (sta<en) {
            if (s[sta]!=s[en]) {
                return false;
            }
            sta++;
            en--;
        }
        return true;
    }*/
};
