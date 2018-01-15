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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0) {
            return NULL;
        }
        TreeNode* root = doBuild(0,0,inorder.size()-1,preorder,inorder);
        return root;
    }
private:
    TreeNode* doBuild(int pos,int left,int right,vector<int> preorder, vector<int> inorder){
        if (left>right) {
            return NULL;
        }
        int middle;
        for(int i = 0; i < inorder.size(); i++){
            if (preorder[pos]==inorder[i]) {
                middle = i;
                break;
            }
        }
        TreeNode* cur = new TreeNode(inorder[middle]);
        cur->left = doBuild(pos+1,left,middle-1,preorder,inorder);
        cur->right = doBuild(pos+(middle-left)+1,middle+1,right,preorder,inorder);
        return cur;
    }
};
