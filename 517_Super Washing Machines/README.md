这道题目，最开始的思路是虽然要求是必须像相邻的machine移动，但是类比于电子，等价于可以随意移动。但是以最大的machine为标杆不能得到正确答案，因为还有一些
数目小，但是大于平均数的machine，不能完全跟随最大标杆一起移动。但是这种情况又比较难归类，比如1,2,3,4,5,6,7这种情况。参考了discuss，每一个machine都可以
统计出左边和右边的总dress数，通过比较这个数值我们知道当前节点需要export或者import节点。具体对应关系为：
L > 0 && R > 0: both sides lacks dresses, and we can only export one dress from current machines at a time, so result is abs(L) + abs®
L < 0 && R < 0: both sides contains too many dresses, and we can import dresses from both sides at the same time, so result is max(abs(L), abs®)
L < 0 && R > 0 or L >0 && R < 0: the side with a larger absolute value will import/export its extra dresses from/to current machine or other side, so result is max(abs(L), abs®)
而每一个节点就意味着一次移动，所以就对应着答案。不用知道其他machine如何移动，对于某一个节点来说，既然最终状况确定，左右侧反映出来的情况一定是真实可信的。
遍历数组，找到最大的那个，就是最后的答案。
