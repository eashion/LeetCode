#简单二叉树遍历
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        int res = doOperate(root);
        if (res==0) {
            return NULL;
        }
        return root;
    }
private:
    int doOperate(TreeNode* node){
        if (node==NULL) {
            return 0;
        }
        int left = 0;
        int right = 0;
        if (node->left!=NULL) {
            left = doOperate(node->left);
        }
        if (node->right!=NULL) {
            right = doOperate(node->right);
        }
        if (left==0) {
            node->left = NULL;
        }
        if (right==0) {
            node->right = NULL;
        }
        return node->val+left+right;
    }
};
