**思路：**题目的意思就是说找一个有向图是否有回路存在。最开始想用并查集去做，但是后来想想并查集可以用来判断无向图，但是有向图却不好判断。</br>
之后想到可以用DFS或者拓扑排序去做，但是自己用数组实现的RE了，可能是数据量大的问题。看了题解才知道在leetcode这种编程环境最常用的还是vector。</br>
以前一直受限于不知道数据范围，无法定义数组。。。另外利用for循环的简写来处理不明确变量类型的数据结构时还是很方便的。</br>
unordered_set/map内部实现是基于hash表的，而set/map是基于红黑树。有时间得把这些数据结构再看看。。。
