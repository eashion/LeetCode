这道题目是找BST中的最小差，最开始的思路想把子树中的最小差求出来，之后和根节点比较。但是这里的问题是无法从根节点中取到最大或最小的值。参考讨论中的解答，
将二叉树按中序遍历，得到的是顺序的序列。而问题求解最小差，就应该把思路朝有序上去思考。思路从一开始就出现了偏颇。