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
    void reorderList(ListNode* head) {
        if( head==NULL || head->next==NULL || head->next->next==NULL ){
            return ;
        }
        ListNode* p = head;
        ListNode* q = head;
        while( p && q && q->next && q->next->next ){
            p = p->next;
            q = q->next->next;
        }
        ListNode* midle = p->next;
        p->next = NULL;
        ListNode* pre = NULL;
        while( midle != NULL ){
            ListNode* next = midle->next;
            midle->next = pre;
            pre = midle;
            midle = next;
        }
        ListNode* h1 = head;
        ListNode* h2 = pre;
        while( h1 && h2 ){
            ListNode* t1 = h1->next;
            h1->next = h2;
            ListNode* t2 = h2->next;
            h2->next = t1;
            h1 = t1;
            h2 = t2;
        }
        return ;
    }
};
