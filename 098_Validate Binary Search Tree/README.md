watch the lower bound and upper bound. like alpha belta prunning.
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return checkValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool checkValidBST(TreeNode* node, long low, long up){
        if (node == NULL) {
            return true;
        }
        if (node->val<=low || node->val>=up) {
            return false;
        }
        return checkValidBST(node->left, low, node->val) && checkValidBST(node->right, node->val, up);
    }
};
```
