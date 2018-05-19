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
