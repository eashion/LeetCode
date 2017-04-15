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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* Thead = new ListNode(0);
        Thead->next = head;
        ListNode* cur = Thead;
        int cnt = m-1;
        while( cnt > 0 ){
            cur = cur->next;
            cnt--;
        }
        ListNode* sta = cur->next;
        ListNode* last = sta;
        ListNode* pre = cur;
        ListNode* tmp = NULL;
        ListNode* next = NULL;
        cnt = (n-m);
        while( cnt >= 0 ){
            next = sta->next;
            sta->next = pre;
            pre = sta;
            sta = next;
            cnt--;
        }
        cur->next = pre;
        last->next = sta;
        return Thead->next;
    }
};
