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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) {
            return res;
        }
        stack<TreeNode*> lis;
        lis.push(root);
        while(!lis.empty()){
            TreeNode* cur = lis.top();
            lis.pop();
            res.push_back(cur->val);
            if (cur->right!=NULL) {
                lis.push(cur->right);
            }
            if (cur->left!=NULL) {
                lis.push(cur->left);
            }
        }
        return res;
    }
};
