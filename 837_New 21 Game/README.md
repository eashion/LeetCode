题目并不是特别复杂，可以看出是一道dp的题目。但是最后始终超时，最开始设计的算法是每次计算所有可能的情况，O(n^2)的时间复杂度，达到十的八次方数量级。超时。
通过看别人的代码，发现其实每次需要计算的情况，可以通过维护一个变量得到，这样O(n)就可以实现。比如计算5，需要包含234，那么在计算6的时候，则要包含345的
情况。相比下来，就是加上了5的情况，减去了过界的情况。而中间部分3,4是不变的。2和5的两个坐标也很好得到。这种题目学习了，下次不能再暴力求解。还是要多思考一步，
另外TLE就是要从时间复杂度下手，降低数量级，不要做无谓的尝试了。
```
double p[20005];
class Solution {
public:
    double new21Game(int N, int K, int W) {
        memset(p,0,sizeof(p));
        p[0]=1;
        double now=0;
        for(int i=1;i<=N;i++)
        {
          if(i-1<K)now=now+p[i-1];
          if(i-W-1>=0&&i-W-1<K)now=now-p[i-W-1];
          p[i]=now/W;
        }
        double ans=0;
        for(int i=K;i<=N;i++)
        {
          ans=ans+p[i];
        }
        /*for(int i=0;i<=100;i++)
        {
          printf("%d:%lf ",i,p[i]);
        }*/
        return ans;
   }
};
```
