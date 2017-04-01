class Solution {
public:
    string simplifyPath(string path) {
        string res,tmp;
        vector<string> dir;
        stringstream ss(path);
        while( getline(ss,tmp,'/') ){
            if( tmp=="" || tmp=="." ){
                continue;
            }
            if( tmp==".." && !dir.empty() ){
                dir.pop_back();
                continue;
            }
            if( tmp != ".." ){
                dir.push_back(tmp);
            }
        }
        for( auto str : dir ){
            res += "/"+str;
        }
        if( res == "" ){
            return "/";
        }
        else{
            return res;
        }
    }
};
