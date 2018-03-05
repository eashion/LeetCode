#Damn...How they find out this is a dp question?
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0;
        map<string, bool> mm;
        map<int, int> mi;
        for(int i = 0; i < p.length(); i++){
            int pos = i+1;
            while(pos<p.length() && (p[pos]-p[pos-1]==1 || p[pos-1]-p[pos]==25)){
                pos++;
            }
            checkSubstr(p,res,i,pos,mm,mi);
            i = pos-1;
        }
        return res;
    }
private:
    void checkSubstr(string p, int& res, int st, int en, map<string, bool>& mm, map<int, int>& mi){
        int len = en-st;
        for(int i = 1; i <= en-st; i++){
            if (mi[i]==26) {
                continue;
            }
            if (len>i+25) {
                res += (26-mi[i]);
                mi[i] = 26;
                continue;
            }
            for(int j = st; j+i<=en; j++){
                string cur = p.substr(j, i);
                if (mm.find(cur)==mm.end()) {
                    res += 1;
                    mm[cur] = true;
					mi[i] += 1;
                }
            }
        }
    }
};



class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0;
        vector<int> dp(26, 0);
        int len = 1;
        dp[p[0]-'a'] = 1;
        for(int i = 1; i < p.length(); i++){
            if (p[i]-p[i-1]==1 || p[i-1]-p[i]==25) {
                len++;
            } else {
                len = 1;
            }
            dp[p[i]-'a'] = max(len, dp[p[i]-'a']);
        }
        for(int i = 0; i < 26; i++){
            res += dp[i];
        }
        return res;
    }
};


int findSubstringInWraproundString(string p) {
	vector<int> letters(26, 0);
	int res = 0, len = 0;
	for (int i = 0; i < p.size(); i++) {
		int cur = p[i] - 'a';
		if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
		if (++len > letters[cur]) {
			res += len - letters[cur];
			letters[cur] = len;
		}
	}
	return res;
}
