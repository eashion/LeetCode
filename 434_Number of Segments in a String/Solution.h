class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        if (s.length()==0) {
            return res;
        }
        bool flag = false;
        for(int i = 0; i < s.length(); i++){
            if (flag && s[i]==' ') {
                res++;
                flag = false;
            } else if (s[i]!=' ') {
                flag = true;
            }
        }
        if (flag) {
            res++;
        }
        return res;
    }
};

public int countSegments(String s) {
    int res=0;
    for(int i=0; i<s.length(); i++)
        if(s.charAt(i)!=' ' && (i==0 || s.charAt(i-1)==' '))
            res++;        
    return res;
}

Time complexity:  O(n)
Space complexity: O(1)
