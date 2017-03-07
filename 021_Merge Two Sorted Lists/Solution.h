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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode tmp(-1);
        ListNode* res = &tmp;
        while( l1!=NULL && l2!=NULL ){
            if( l1->val < l2->val ){
                res->next = l1;
                l1 = l1->next;
            }
            else{
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if( l1 == NULL ){
            res->next = l2;
        }
        else{
            res->next = l1;
        }
        return tmp.next;
    }
};
