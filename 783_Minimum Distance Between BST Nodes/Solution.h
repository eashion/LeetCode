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
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        int pre = -1;
        search(root, res, pre);
        return res;
    }
private:
    void search(TreeNode* node, int& res, int& pre){
        if (node->left!=NULL) {
            search(node->left, res, pre);
        }
        if (pre!=-1) {
            res = min(res, node->val-pre);
        }
        pre = node->val;
        if (node->right!=NULL) {
            search(node->right, res, pre);
        }
        return ;
    }
};
