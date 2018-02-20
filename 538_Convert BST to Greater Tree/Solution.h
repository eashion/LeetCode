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
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        int right = convert(root->right, 0);
        root->val += right;
        convert(root->left, root->val);
        return root;
    }
    int convert(TreeNode* node, int val){
        if (node==NULL) {
            return 0;
        }
        int right = 0;
        if (node->right != NULL) {
            right = convert(node->right, val);
        }
        node->val += right;
        int left = convert(node->left, node->val+val);
        int res = node->val+left;
        node->val += val;
        return res;
    }
};
