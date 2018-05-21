这道题目还是比较有意思的，给出了要求的prime number，ugly number只包含给定的prime factor最开始的思路想做减法，把所有不符合条件的数删掉，这样的时间复杂
度与数字的大小有关，受不了。也想过利用现有的数字生成新的数字，但是没有理清关系。首先，每个新生成的数可能与所有的prime number相乘，根据这一点，利用优先队列
和map可以A掉，但是效率堪忧。可以优化的地方在于，可以根据已经生成的数为对象，用prime number去乘。所以每个prime number只要保存下来位置，然后依次递增就可以。
这样for循环里面套两个并列for循环，一个更新数字，一个更新位置。其实每次更新位置的prime number，是当前value相同的几个，所以可以新建value数组，这样就可以把
更新数字和更新位置放在一个里面做。将ugly number的更新提前一步，先更新ugly number，然后通过更新value，得到下一个ugly number。
```
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 0);
        vector<int> idx(primes.size(), 0);
        vector<int> val(primes.size(), 1);
        int next = 1;
        for(int i = 0; i < n; i++){
            ugly[i] = next;
            next = INT_MAX;
            for(int j = 0; j < primes.size(); j++){
                if (val[j]==ugly[i]) {
                    val[j] = ugly[idx[j]++]*primes[j];
                }
                next = min(next, val[j]);
            }
        }
        return ugly[n-1];
    }
    /*
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, INT_MAX);
        vector<int> idx(primes.size(), 0);
        ugly[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < primes.size(); j++){
                ugly[i] = min(ugly[i], primes[j]*ugly[idx[j]]);
            }
            for(int j = 0; j < primes.size(); j++){
                while(ugly[idx[j]]*primes[j] <= ugly[i])
                    idx[j]++;
            }
        }
        return ugly[n-1];
    }
    */
};
```
