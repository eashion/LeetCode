**思路:** 利用这道题熟悉一下目录结构，"/."表示当前目录，"/.."表示上一级目录。了解这个之后就会发现其实是类似栈的操作，最后把栈内的目录按顺序输出。注意如果栈内为空，要输出一个"/"。另外stringstream在各种数据类型转换为string以及字符串分割时也非常方便。