class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        if (s.length()==0) {
            return res;
        }
        int pos = s.length()-1;
        while(pos>=0 && s[pos]==' '){
            pos--;
        }
        for(int i = pos; i >= 0; i--){
            if (s[i]==' ') {
                break;
            }
            res++;
        }
        return res;
    }
};
