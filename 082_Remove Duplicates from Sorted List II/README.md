pay attention to the first one, don't choose a random number, because the input is random. Use flag as a flag.
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) {
            return head;
        }
        ListNode* tophead = new ListNode(-1);
        tophead->next = head;
        ListNode* p = head;
        ListNode* pre = tophead;
        int cur = INT_MAX;
        bool flag = true;
        while(p != NULL){
            if (flag==false && p->val==cur) {
                pre->next = p->next;
            } else {
                if (p->next!=NULL && p->next->val==p->val) {
                    pre->next = p->next;
                    cur = p->val;
                    flag = false;
                } else {
                    pre = p;
                }
            }
            p = p->next;
        }
        return tophead->next;
    }
};
```
