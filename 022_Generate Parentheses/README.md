枚举二进制数字的方法比较简单，但是没有位运算速度太慢了。
```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("",0,n,res);
        return res;
    }
private:
    void dfs(string ans,int cur,int n,vector<string>& res){
        //cout<<ans<<endl;
        if (ans.length()==2*n) {
            if (cur == 0) {
                res.push_back(ans);
            }
            return ;
        }
        if (cur<n && cur<=(2*n-ans.length())) {
            dfs(ans+"(",cur+1,n,res);
        }
        if (cur > 0) {
            dfs(ans+")",cur-1,n,res);
        }
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int sum = pow(2,2*n);
        for(int i = 0; i < sum; i++){
            string cur = check(i,n);
            if (cur != "") {
                res.push_back(cur);
            }
        }
        return res;
    }
private:
    string check(int num,int n){
        int sum = 0;
        int cnt = 2*n;
        string ans = "";
        while(cnt--){
            int cur = num%2;
            num /= 2;
            sum += cur==0?-1:1;
            ans += cur==0?")":"(";
            if (sum<0 || sum>n || (cnt<sum)) {
                return "";
            }
        }
        return sum==0?ans:"";
    }
};
```
```
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int checkValidPara(unsigned int hex)
{
    int balanceCount = 0;
   // printf("\n %x", hex);
    unsigned int mask = 1;
    while (hex)
    {
        unsigned int lsb =  (hex & mask);
        hex &= ~mask;
        mask <<= 1;
        //printf("\n %x", lsb);
        // closing bracket
        if (lsb && (balanceCount == 0))
        {
            // opening bracket seen at the end, not balanced
            return 0;
        } else if (lsb == 0)
        {
            balanceCount++;
        } else if (lsb && balanceCount)
        {
            balanceCount--;
        }
    }
    if (balanceCount == 0)
    {
        return 1;
    }
    return 0;
}
char** generateParenthesis(int n, int* returnSize) {
    unsigned int array[(1 << n*2)/2 + 1], validCount, paranthesisHex;
    unsigned int parHex;
    int i;
    if (n == 0) return 0;
    for (i = 0; i < ((1 << n*2)/2 + 1); i++)
    {
        array[i] = 0;
    }
    validCount = 0;
    parHex = 1 << (n*2-1);
    //parHex = 0x2a;
    printf("\n %x", parHex);
    while (parHex < (1 << (n*2)))
    {
        if (checkValidPara(parHex))
        {
            array[validCount] = parHex;
            printf("\n Valid  = %x", parHex);
            validCount++;
        }
        parHex += 1;
    }
    if (validCount)
    {
        char **cppAr = (char**)malloc(sizeof(char*) * validCount);
        if (cppAr == NULL)
            return 0;
        printf("\n error here1");
        *returnSize = 0;
        for (i = 0; i < validCount; i++)
        {
            char *p = (char*) malloc(sizeof(char) * (n * 2 + 1));
            if (p == NULL)
                return 0;
            int k = 0;
            unsigned int j = 1 << (n *2 - 1);
                    printf("\n error here2");
            while (j)
            {
                if (array[i]&j)
                {
                    p[k++]= '(';
                }else
                {
                    p[k++] = ')';
                }
                j >>= 1;
            }
            p[k] = 0;
    printf("\n %s", p);
            *(cppAr+*returnSize) = p;
            *returnSize+=1;
                    printf("\n error here4");
        }
                printf("\n error here5");
        return cppAr;
    }
    return 0;
}
```
