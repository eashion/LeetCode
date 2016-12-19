*题意：*找到不含重复字符的最长子串。  
*思路：*最开始的思路是枚举起点和终点，但是很快否决了，因为O(N^2)的时间复杂度太高了。。之后想用二分，但是仔细想了一下发现二分对于这种要求
连续的题目其实并不是特别适合。后来想到贪心，但是开始的时候贪心的思路错了。起点的思路是对的，一定是由于某个字符出现重复来重置起点；但是
终点不在第二次出现该字母的地方，而是继续往后，直到该字母出现第三次或者到了字符串结尾。也就是说我们记录字符的出现位置（ASCII，数组小于200），
当某个字母第二次出现时我们抛掉第一次出现，从第一次后计算包含第二次在内的最长子串。O(N)的时间复杂度。
第一次写的代码：<pre><code>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int sta = 1;
        int pos[200];
        int res = 0;
        memset(pos,0,sizeof(pos));
        for( int i = 0; i < len; i++ ){
            int tmp = (int)s[i];
            if( pos[tmp] == 0 ){
                pos[tmp] = i+1;
            }
            else{
                res = max(res,i-sta+1);
                memset(pos,0,sizeof(pos));
                sta = i+1;
                pos[tmp] = i+1;
            }
            if( i == len-1 ){
                res = max(res,len+1-sta);
            }
        }
        sta = len;
        memset(pos,0,sizeof(pos));
        for( int i = len-1; i >= 0; i-- ){
            int tmp = (int)s[i];
            if( pos[tmp] == 0 ){
                pos[tmp] = i+1;
            }
            else{
                res = max(res,sta-i);
                memset(pos,0,sizeof(pos));
                sta = i+1;
                pos[tmp] = i+1;
            }
            if( i == 0 ){
                res = max(res,sta);
            }
        }
        return res;
    }
};
</code></pre>
对于样例：asjrgapa输出错误结果！  
后来参考了别人的代码，但是觉得很亏，本来自己可以的，差一点。
