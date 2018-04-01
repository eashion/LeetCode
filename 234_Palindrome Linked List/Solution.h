//Use O(1) spacemay represents can operate the initial linked list. But I thin mine is O(1), even thount not very efficient.
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
    bool isPalindrome(ListNode* head) {
        if (head==NULL) {
            return true;
        }
        string record = "";
        int cnt = 0;
        ListNode* p = head;
        while(p!=NULL){
            record += to_string(p->val);
            p = p->next;
            cnt++;
        }
        p = head;
        cnt/=2;
        string left = "";
        while(p!=NULL && cnt>0){
            left = to_string(p->val)+left;
            cnt--;
            p = p->next;
        }
        reverse(record.begin(), record.end());
        reverse(left.begin(), left.end());
        record = record.substr(0, left.length());
        return record==left;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};
