**思路：** 最开始的时候想到之前做过的利用两个栈解决多项式问题的方法，虽然不太确定但是还是摸索着尝试了一下。缝缝补补过了样例，但是最后没有实现，TLE。确实写的太复杂了一点。
现在想起来了利用双栈是解包含左右括号的多项式加减乘除的，这里的话不需要考虑那么复杂，是思路落入套路里面了。跳出利用双栈的思路，发现题目并没有那么复杂。
因为不涉及的括号，所以其实就是一个遍历，出现乘除的时候涉及到前后两个数，其余时候我们只需要判断数的正负就可以了。把正负和数值绑定起来放进堆栈后我们就把所有
的问题转化为了求和的问题，大大简化了题目。哎，还是太死板了。对待这种面试的题目要跳出来去思考，否则一旦落入思维定式就太被动了。
