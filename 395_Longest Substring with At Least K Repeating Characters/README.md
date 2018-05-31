This problem takes lots of time. It's not dp, not greedy. At first, it's hard to find an appropriate algorithm. I know I should start from
the bad characters, which is less than k. And I don't need to calculate count of characters every time. 1. finally I choose a kind of 
dc. Seperate string with the largest invalid character. Although I traversal substr everytime. This algorithm proves efficient. 2. In discussion, 
I found a more concise version. Enumerate h, the number of different characters in substring. Use two pointers to parse the whole string.
During this process, if the number of unique characters is equal to h, and the number of characters which count is greater than k is equal to
 h. Which means the current substring is a perfect valid substring. Then update res. Excellent algorithm. The second algorithm have better runtime
 complexity.
 ```
 class Solution {
public:
    int longestSubstring(string s, int k) {
        //s= "ababbc";
        //k = 2;
        int res = 0;
        for(int h = 1; h <= 26; h++){
            int left = 0;
            int right = 0;
            int unique = 0;
            int numofsatisfy = 0;
            vector<int> cnt(26, 0);
            while(right < s.length()){
                if (unique <= h) {
                    int idx = s[right]-'a';
                    if (cnt[idx] == 0) 
                        unique++;
                    cnt[idx]++;
                    if (cnt[idx] == k) 
                        numofsatisfy++;
                    right++;
                } else {
                    int idx = s[left]-'a';
                    if (cnt[idx] == k) 
                        numofsatisfy--;
                    cnt[idx]--;
                    if (cnt[idx] == 0) 
                        unique--;
                    left++;
                }
                if (unique==h && numofsatisfy==h) 
                    res = max(res, right-left);
            }
        }
        return res;
    }
};
 ```
 ```
 class Solution {
public:
    int longestSubstring(string s, int k) {
        //s = "ababbc";
        //k = 2;
        int res = 0;
        parseValid(s,k,res);
        return res;
    }
private:
    void parseValid(string s, int k, int& res){
        if (s.length() < k) {
            return ;
        }
        map<char, int> count;
        for(int i = 0; i < s.length(); i++){
            count[s[i]]++;
        }
        int cnt = -1;
        char flag = '0';
        for(auto iter = count.begin(); iter != count.end(); iter++){
            if (iter->second<k && iter->second>cnt) {
                cnt = iter->second;
                flag = iter->first;
            }
        }
        if (cnt == -1) {
            res = max(res, (int)s.length());
            return ;
        }
        int pre = 0;
        //cout<<"flag: "<<flag<<endl;
        //cout<<"parse: "<<s<<endl;
        for(int i = 0; i < s.length(); i++){
            if (s[i] == flag) {
                //cout<<"pos: "<<pre<<endl;
                string tmp = s.substr(pre, i-pre);
                pre = i+1;
                parseValid(tmp, k, res);
            }
        }
        if (s[s.length()-1] != flag) {
            string tmp = s.substr(pre, s.length()-pre);
            parseValid(tmp, k, res);
        }
        return ;
    }
};
 ```
