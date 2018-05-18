利用dfs可以实现题目要求的constant space，技巧在于先把右边的安排好。
```
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root==NULL || (root->left==NULL && root->right==NULL)) {
            return ;
        }
        TreeLinkNode* last = NULL;
        if (root->left!=NULL && root->right!=NULL) {
            root->left->next = root->right;
            last = root->right;
        } else if (root->left==NULL) {
            last = root->right;
        } else if (root->right==NULL) {
            last = root->left;
        }
        TreeLinkNode* next = root->next;
        while(next!=NULL){
            if (next->left!=NULL) {
                last->next = next->left;
                break;
            }
            if (next->right!=NULL) {
                last->next = next->right;
                break;
            }
            next = next->next;
        }
        connect(root->right);
        connect(root->left);
        return ;
    }
};
```
