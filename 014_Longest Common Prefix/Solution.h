class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if( strs.size() == 0 ){
            return "";
        }
        string tmp = strs[0];
        int len = tmp.length();
        for( int i = 1; i < (int)strs.size(); i++ ){
            if( len > strs[i].length() ){
                len = strs[i].length();
            }
            for( int j = 0; j < len; j++ ){
                if( strs[i][j] != tmp[j] ){
                    len = j;
                    break;
                }
            }
        }
        return tmp.substr(0,len);
    }
};
