**思路：**</br>
题目是找到完全二叉树的节点数目，要利用上完全二叉树的性质。完全二叉树的定义如下：</br>
```
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes at the last level h.
```
除了最后一层每一层都是满的，目标在于找到最后一层少多少个。解题思路也是按照这个方向去的，虽然可以AC，但是好像效率不是特别高。
看到题解的方法是while循环找到最左深度和最右深度，如果相等，就是一棵满二叉树，利用满二叉树性质求节点数；否则递归求子树节点数之和。这样确实能提高不少的效率。
觉得自己在做题的时候思路总是放不开，不够大胆。其实这道题最开始的关注点放到最后一层就不太好，毕竟最后一层还是要递归进去到底。而题解把关注点放在子树是否是满
二叉树就很方便。对于完全二叉树来说大部分子树还是满的，我们只要找到临界点就行了。而利用最左深度和最右深度判断是否满足满二叉树确实是挺棒的一个想法。
