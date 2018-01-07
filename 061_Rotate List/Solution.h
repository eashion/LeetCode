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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || k==0) {
            return head;
        }
        ListNode* p = head;
        int cnt = 1;
        while (p->next!=NULL) {
            p = p->next;
            cnt++;
        }
        if (k%cnt==0) {
            return head;
        }
        p->next = head;
        cnt = cnt-(k%cnt);
        while (cnt--) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
