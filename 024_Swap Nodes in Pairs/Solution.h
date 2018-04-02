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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow!=NULL && fast!=NULL){
            int tmp = slow->val;
            slow->val = fast->val;
            fast->val = tmp;
            slow = fast->next;
            fast = slow==NULL?slow:slow->next;
        }
        return head;
    }
};
