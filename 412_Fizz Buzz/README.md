**题意：**
3的倍数特别输出，5的倍数特别输出，3&5的倍数特别输出。   
**思路：**
就是O(n)的遍历,因为3&5的倍数输出的特点可以利用字符串的相加。少了两次取余速度快了6ms。
<pre><code>
std的全局函数
std::to_string();
string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val)
</code></pre>
