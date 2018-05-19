可以同时利用random和next去构造链表，因为最终都会完全构造，构造完成后存入map，因为map公用的，所以能够保证每个节点生成一遍。
```
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*> mm;
        RandomListNode* res = buildNewList(head,mm);
        traverseList(res,head,mm);
        return res;
    }
private:
    RandomListNode* buildNewList(RandomListNode* last,map<RandomListNode*,RandomListNode*>& mm){
        if (last==NULL) {
            return NULL;
        }
        RandomListNode* cur = new RandomListNode(last->label);
        mm[last] = cur;
        cur->next = buildNewList(last->next,mm);
        return cur;
    }
    void traverseList(RandomListNode* after, RandomListNode* pre, map<RandomListNode*,RandomListNode*>& mm){
        if (after==NULL && pre==NULL) {
            return ;
        }
        after->random = pre->random==NULL?NULL:mm[pre->random];
        traverseList(after->next, pre->next, mm);
    }
};

public RandomListNode copyRandomList(RandomListNode head) {
        return helper(head, new HashMap<RandomListNode, RandomListNode>());
 } 
    
 private RandomListNode helper(RandomListNode node, Map<RandomListNode,RandomListNode> map){
        if(node == null)
            return node;
        if(map.containsKey(node))
            return map.get(node);
        RandomListNode newNode = new RandomListNode(node.label);
        map.put(node, newNode);
        newNode.next = helper(node.next, map);
        newNode.random = helper(node.random, map);
        return newNode;
  }
```
