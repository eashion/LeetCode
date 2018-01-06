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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        int cur = -1;
        traversalTree(root,cur,res);
        return res;
    }
private:
    void traversalTree(TreeNode* root, int &cur, int &res){
        if (root->left!=NULL) traversalTree(root->left,cur,res);
        if (cur>=0) res = min(res,root->val - cur);
        cur = root->val;
        if (root->right!=NULL) traversalTree(root->right,cur,res);
    }
};
