**思路：**</br>两个固有的有序链表合并。不需要开辟另外的空间，只需要比较大小后将原来的节点重新连接就好了。可以优化的一点在于前面可以设置一个空节点，这样就少了一个判断，代码更加简洁。