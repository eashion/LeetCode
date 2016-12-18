
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up = 0;
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while( l1!=NULL || l2!=NULL ){
            up = 0;
            int n1 = 0;
            if( l1 != NULL ){
                n1 = l1->val;
                l1 = l1->next;
            }
            int n2 = 0;
            if( l2 != NULL ){
                n2 = l2->val;
                l2 = l2->next;
            }
            cur->val = cur->val+n1+n2;
            if( cur->val >= 10 ){
                up = cur->val/10;
                cur->val = cur->val%10;
            }
            if( l1!=NULL || l2!=NULL || up!=0 ){
                cur->next = new ListNode(up);
                cur = cur->next;
            }
        }
        return res;
    }
};
