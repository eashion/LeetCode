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
    bool isBalanced(TreeNode* root) {
        return deep(root)!=-1;
    }
private:
    int deep(TreeNode* root){
        if( root == NULL ){
            return 0;
        }
        int d1 = deep(root->left);
        int d2 = deep(root->right);
        if( d1==-1 || d2==-1 || abs(d1-d2)>1 ){
            return -1;
        }
        return max(d1,d2)+1;
    }
};
