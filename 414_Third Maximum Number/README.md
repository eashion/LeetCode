**题意：**
找出一列整数中的第三大的数，如果不存在，输出第一大。注意是第三大，所以[1,2,2,3]输出的结果是1.  
**思路：**
最开始的时候想到用优先队列，小顶堆维护size不大于3。但是后面发现优先队列无法排除上面[1,2,2,3]数字相等的情况。
之后选择开一个大小为3的数组，然后if，else考虑所有可能的情况。虽然可以AC，但是还是笨了一点。看了Discuss里面的牛逼代码，用的是set维护。。。内部实现是平衡二叉树，多好的性质啊，即排重还有序。因为之前没用到过，没想到，受教了。
另外学习了以后priority_queue这么写：
<pre><code>
priority_queue<int> que;//大顶堆  
priority_queue<int,vector<int>,greater<int> > queue;//小顶堆  
</code></pre>
LeetCode上面的题目大多是面试题，所以直接在编辑框Coding更符合实际情况一些。另外Pick one真的挺好用的。   
set实现：
<pre><code>
int thirdMax(vector<int>& nums) {
    set<int> top3;
    for (int num : nums) {
        top3.insert(num);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
}
</code></pre>
