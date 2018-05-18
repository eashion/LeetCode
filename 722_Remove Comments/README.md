class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        //source = {"void func(int k) {", "// this function does nothing /*", "   k = k*2/4;", "   k = k/2;*/", "}"};
        //source = {"a/*comment", "line", "more_comment*/b"};
        vector<string> res;
        string cur = "";
        int flag = 0;
        for(int i = 0; i < source.size(); i++){
            for(int j = 0; j < source[i].length(); j++){
                if (flag==0 && source[i][j]=='/' && j+1<source[i].length()) {
                    if (source[i][j+1]=='/') {
                        j++;
                        flag = 1;
                        break;
                    } else if (source[i][j+1]=='*') {
                        j++;
                        flag = 2;
                    }
                } else if (flag==2 && source[i][j]=='*') {
                    if (flag==2 && j+1<source[i].length() && source[i][j+1]=='/') {
                        j++;
                        flag = 0;
                        continue;
                    }
                }
                if (flag==0) {
                    cur += source[i][j];
                }
            }
            if (flag != 2) {
                if (!cur.empty()) {
                    res.push_back(cur);
                }
                cur = "";
                flag = 0;
            }
        }
        return res;
    }
};
