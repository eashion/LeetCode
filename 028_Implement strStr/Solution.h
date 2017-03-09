class Solution {
public:
    int strStr(string haystack, string needle) {
        if( needle.length() == 0 ){
            return 0;
        }
        int next[needle.length()+1];//长度+1
        getNext(needle,next);
        int j = 0;
        //此处与getNext不同在于从第0个字符开始比较
        for( int i = 0; i < haystack.length(); i++ ){
            while( j>0 && haystack[i]!=needle[j] ){
                j = next[j];
            }
            if( haystack[i] == needle[j] ){
                j++;
                if( j == needle.length() ){
                    return i-j+1;
                }
            }
        }
        return -1;
    }
private:
    void getNext(string needle,int* next){
        next[0] = next[1] = 0;//next[i]表示前i个字母前后最长公共部分
        int j = 0;
        //此处计算next[2~n]，所以要先从第1个字符和第0个比较
        for( int i = 1; i < needle.length(); i++ ){
            while( j>0 && needle[i]!=needle[j] ){
                j = next[j];
            }
            if( needle[i] == needle[j] ){
                j++;
            }
            next[i+1] = j;
        }
        return ;
    }
};
