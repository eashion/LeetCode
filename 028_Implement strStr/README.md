**思路：**心想着一道简单题为什么会出现KMP算法，原来暴力也能做，数据太弱了。但是还是趁着又把KMP复习了一下，因为直接还是写不出来。。感觉KMP最关键的就是理解好next数组的含义：next[i]表示长度为i的前后公共串长度(next[i]<i)。另外就是要注意getNext函数里for循环的起点和比较函数里for循环的起点是不同的。