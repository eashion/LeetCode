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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL || (root->left==NULL && root->right==NULL)) {
            return true;
        }
        bool res = true;
        doCompare(root->left,root->right,res);
        return res;
    }
private:
    void doCompare(TreeNode* left,TreeNode* right,bool &res){
        if (!res) {
            return ;
        }
        if (left==NULL && right==NULL) {
            return ;
        }
        if (left==NULL || right==NULL) {
            res = false;
            return ;
        }
        if (left->val!=right->val) {
            res = false;
            return ;
        }
        doCompare(left->left,right->right,res);
        doCompare(left->right,right->left,res);
    }
};

