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
    int maxDepth(TreeNode* root) {
        return findDeep(root);
    }
private:
    int findDeep(TreeNode* node){
        if( node == NULL ){
            return 0;
        }
        return 1+max(findDeep(node->left),findDeep(node->right));
    }
};
