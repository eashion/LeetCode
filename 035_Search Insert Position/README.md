**思路：** 合理的方法是二分，因为是有序，要找到插入的位置,等同于lowerbound。对二分的边界一直特别困惑，写的时候也需要试好几次才能写对。。二分注意区间的开闭。lowerbound:mid=l+(r-l)/2;//(l+r)为奇数时靠近l一点;upperbound:mid=l+(r-l+1)/2;//(r+l)为奇数时离r近一点
