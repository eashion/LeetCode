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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL) {
            return t2;
        }
        if (t2==NULL) {
            return t1;
        }
        return merge(t1,t2);
    }
private:
    TreeNode* merge(TreeNode* t1, TreeNode* t2){
        if (t2==NULL) {
            return t1;
        }
        t1->val += t2->val;
        if (t1->left==NULL && t1->right!=NULL) {
            t1->left = t2->left;
            t1->right = merge(t1->right,t2->right);
        } else if (t1->right==NULL && t1->left!=NULL) {
            t1->right = t2->right;
            t1->left = merge(t1->left,t2->left);
        } else if (t1->left==NULL && t1->right==NULL) {
            t1->left = t2->left;
            t1->right = t2->right;
        } else {
            t1->left = merge(t1->left,t2->left);
            t1->right = merge(t1->right,t2->right);
        }
        return t1;
    }
};
