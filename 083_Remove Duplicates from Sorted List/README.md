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
        map<int, int> mm;
        if (head==NULL) {
            return head;
        }
        ListNode* p = head;
        mm[p->val] = 1;
        while(p->next != NULL){
            if (mm[p->next->val] == 1) {
                p->next = p->next->next;
            } else {
                mm[p->next->val] = 1;
                p = p->next;
            }
        }
        return head;
    }
};
```
