/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Opt{
    int val;
    int cl;
    int gcl;
    Opt(){}
    Opt(int val, int cl, int gcl){
        this->val = val;
        this->cl = cl;
        this->gcl = gcl;
    }
};
class Solution {
public:
    int rob(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        Opt res = search(root);
        return res.val;
    }
private:
    Opt search(TreeNode* root){
        if (root->left==NULL && root->right==NULL) {
            Opt res(root->val, 0, 0);
            return res;
        }
        Opt res(0,0,0);
        if (root->left!=NULL) {
            Opt left = search(root->left);
            res.cl += left.val;
            res.gcl += left.cl;
        }
        if (root->right!=NULL) {
            Opt right = search(root->right);
            res.cl += right.val;
            res.gcl += right.cl;
        }
        res.val = max(res.cl, res.gcl+root->val);
        return res;
    }
};
