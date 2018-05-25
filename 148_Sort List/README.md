Master theorem is import.
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
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode* ph = head;
        while(ph != NULL){
            size++;
            ph = ph->next;
        }
        if (size <= 1) {
            return head;
        }
        head = mergeSort(head, size);
        return head;
    }
private:
    ListNode* mergeSort(ListNode* node, int size){
        if (size == 1) {
            return node;
        }
        ListNode* left;
        ListNode* mid;
        ListNode* right;
        left = node;
        int tmp = size/2;
        while(tmp--){
            mid = node;
            node = node->next;
        }
        tmp = size/2;
        mid->next = NULL;
        right = node;
        left = mergeSort(left, tmp);
        right = mergeSort(right, size-tmp);
        mid = new ListNode(-1);
        ListNode* head = mid;
        while(left!=NULL && right!=NULL){
            if (left->val < right->val) {
                mid->next = left;
                left = left->next;
            } else {
                mid->next = right;
                right = right->next;
            }
            mid = mid->next;
        }
        if (left != NULL) {
            mid->next = left;
        }
        if (right != NULL) {
            mid->next = right;
        }
        return head->next;
    }
};
```
