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
    int findSecondMinimumValue(TreeNode* root) {
        int second = INT_MAX;
        int first = INT_MAX;
        dfs(root, second, first);
        return second==INT_MAX?-1:second;
    }
private:
    void dfs(TreeNode* node, int& second, int& first){
        if (node==NULL || node->val>=second) {
            return ;
        }
        if (first > node->val) {
            second = first;
            first = node->val;
        } else if (first < node->val) {
            second = node->val;
        }
        dfs(node->left, second, first);
        dfs(node->right, second, first);
    }
};
```
