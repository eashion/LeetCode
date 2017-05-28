**思路：** 这道题的关键在于如何判断小数部分是循环的。最开始以为是一道字符串的题，但是没有思路。后来参考了题解，明白找到循环的关键在于余数是否重复出现。题
解上面的解析写的很好，贴在下面：
```
Well, the key to this problem is on how to identify the recurring parts. After doing some examples using pen and paper, you may find that for the decimal parts to recur, the remainders should recur. So we need to maintain the remainders we have seen. Once we see a repeated remainder, we know that we have reached the end of the recurring parts and should enclose it with a ). However, we still need to insert the ( to the correct position. So we maintain a mapping from each remainder to the position of the corresponding quotient digit of it in the recurring parts. Then we use this mapping to retrieve the starting position of the recurring parts.

Now we have solved the trickiest part of this problem.

There are some remaining problems to solve to achieve a bug-free solution.

Pay attention to the sign of the result;
Handle cases that may cause overflow like numerator = -2147483648, denominator = -1 appropriately by using long long;
Handle all the cases of (1) no fractional part; (2) fractional part does not recur; and (3) fractional part recurs respectively.
To handle problem 3, we divide the division process into the integral part and the fractional part. For the fractional part, if it does not recur, then the remainder will become 0 at some point and we could return. If it does recur, the method metioned in the first paragraph has already handled it.

Taking all these into considerations, we have the following code, which takes 0 ms :-)
```
按照题解的思路完成了代码，其中边界问题比较坑人，需要特别注意。另外to_string()函数可以将任意形式的数值转换为string，真的太方便了。
