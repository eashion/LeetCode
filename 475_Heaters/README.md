和萨拉曼的军队不同，这道题目的heater位置已经确定，要找到范围。对于heater来说，要根据位置去覆盖house有些困难，思路是根据房子，找到左右界的heater。我采用的方法
是两个数组均排序，然后滑动left&right区间。时间复杂度在O(nlogn+mlogm+n+m)，总体来说效率还不错。discussion中有一个答案，仅排序heater，然后binarysearch
找上下界。时间复杂度应该在O(nlogn+n*logm);
