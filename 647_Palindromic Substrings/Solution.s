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
