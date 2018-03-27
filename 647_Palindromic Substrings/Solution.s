#O(n^3) is a little expensive
class Solution {
public:
    int countSubstrings(string s) {
        //s = "aaaa";
        vector<int> opt(s.length(), 0);
        opt[0] = 1;
        for(int i = 1; i < s.length(); i++){
            opt[i] = opt[i-1]+1;
            for(int k = 0; k < i; k++){
                if (check(k,i,s)) {
                    opt[i]++;
                }
            }
            //cout<<opt[i]<<' ';
        }
        return opt[s.length()-1];
    }
private:
    int check(int x, int y, string s){
        while(s[x]==s[y] && x<y){
            x++;
            y--;
        }
        //cout<<"x:"<<x<<" "<<y<<endl;
        if (x==y || x==y+1) {
            return true;
        }
        return false;
    }
};


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
        }
        return res;
    }
};
