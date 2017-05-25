class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int mm[30];
        int mcnt[30];
        vector<int> res;
        int cnt[p.length()+1];
        memset(mm,0,sizeof(mm));
        memset(mcnt,0,sizeof(mcnt));
        memset(cnt,0,sizeof(cnt));
        int tmp = 0;
        for( int i = 0; i < p.length(); i++ ){
            tmp = p[i]-'a';
            mm[tmp] = i+1;
            mcnt[tmp]++;
        }
        for( int i = 0; i < s.length(); i++ ){
            if( mm[s[i]-'a'] != 0 ){
                bool flag = true;
                int pos = 0;
                for( int j = 0; j < p.length(); j++ ){
                    pos = i+j;
                    if( pos >= s.length() ){
                        flag = false;
                        break;
                    }
                    tmp = s[pos]-'a';
                    if( mm[tmp] == 0 ){
                        flag = false;
                        break;
                    }
                    cnt[mm[tmp]] += 1;
                    if( cnt[mm[tmp]] > mcnt[tmp] ){
                        flag = false;
                        break;
                    }
                }
                if( flag == true ){
                    res.push_back(i);
                }
                memset(cnt,0,sizeof(cnt));
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26,0),sv(26,0),res;
        if( p.length() > s.length() ){
            return res;
        }
        for( int i = 0; i < p.length(); i++ ){
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if( pv == sv ){
            res.push_back(0);
        }
        for( int i = p.length(); i < s.length(); i++ ){
            ++sv[s[i]-'a'];
            --sv[s[i-p.length()]-'a'];
            if( sv == pv ){
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};
