**思路:** 开始的时候没有思路，能想到的方法只有O(n^2)的遍历，但是超时WA掉。</bar>
有两个问题不好解决：</bar>
1.如何动态表示长度为K的空间内的数值;</bar>
2.如何快速的找到符合绝对值符合条件的数;</bar>
参考题解，发现题解使用set解决了这个问题，一是因为set可以很方便的删除元素，方便维护;二是set自动有序，把绝对值关系|a-b|<=t转化为-t<a-b<t之后利用lower_bound可以很方便的去查找。最后的时间复杂度大约为O(nlgk)，不会超时。另外要注意int超界的问题，set里放入长整型。发现很多这种要求时间的题目都是利用特殊的数据结构去解决，拿空间换时间。下次没有思路的时候可以多往set,map这些数据结构上想一想。