这道题目想了很久一直没有思路。可以知道的是枚举中间点，将BST分为两个部分单独生成，然后搭配。最开始纠结的地方在于用什么办法解，使用搜索，但是似乎没有一个清晰地最终态。并且，当前生成的树如何存储，因为这道题目需要返回的
是一个头结点的vector，所以每条树都是需要生成的。
首先，是如何生成的问题，因为很明显需要每个树都生成，并且利用BST的性质，枚举区间内的各个节点，想到递归。生成所有子树后，左右子树搭配，n*m。
其次，如何存储。在思考的时候有考虑过调用函数内申请空间，这个空间如何回收的问题。作为对象的返回值，会跟随对象一起销毁，不是函数调用结束就销毁。
http://blog.csdn.net/somehow1002/article/details/50206589 所以既然最终的状态不好确定，就应该在最顶层，或者理解为每一层构造树，左右子树构造好以后申请
根节点。所以思路就很清晰了，左右子树同样是以vector的形式传回的，每一层做一个组装。
