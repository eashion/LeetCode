class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1,v2;
        while( true ){
            v1 = getV(version1);
            v2 = getV(version2);
            if( v1 > v2 ){
                return 1;
            }
            else if( v1 < v2 ){
                return -1;
            }
            //注意"1.0"vs"1"，要等
            if( version1.length()==0 && version2.length()==0 ){
                break;
            }
        }
        return 0;
    }
private:
    int getV(string &version){
        int len = version.length();
        int ver = 0;
        int pos = len;
        for( int i = 0; i < len; i++ ){
            if( version[i] == '.' ){
                pos = i+1;
                break;
            }
            ver = ver*10+(version[i]-'0');
        }
        version = version.substr(pos,len);
        return ver;
    }
};
