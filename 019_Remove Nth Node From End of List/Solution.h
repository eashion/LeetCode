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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* npre = new ListNode(0);
        npre->next = head;
        ListNode* np = head;
        int cnt = 0;
        while(p->next!=NULL){
            cnt++;
            if(cnt>=n){
                npre = npre->next;
                np = np->next;
            }
            p = p->next;
        }
        if (np==head) {
            head = head->next;
        } else {
            npre->next = np->next;
        }
        return head;
    }
};
