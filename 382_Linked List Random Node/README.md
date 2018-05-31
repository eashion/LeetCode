http://blog.jobbole.com/42550/
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
private:
    ListNode* local;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        local = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* pos = local;
        int res = pos->val;
        for(int i = 1; pos->next!=NULL; i++){
            pos = pos->next;
            if (rand()%(i+1) == i) {
                res = pos->val;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
```
