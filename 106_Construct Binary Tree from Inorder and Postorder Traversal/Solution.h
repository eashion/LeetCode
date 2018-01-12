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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        TreeNode* root = doBuild(0,len-1,len-1,inorder,postorder);
        return root;
    }
private:
    TreeNode* doBuild(int left,int right,int pos,vector<int> inorder,vector<int> postorder){
        TreeNode* cur = new TreeNode(0);
        if (left==right) {
            cur->val = postorder[pos];
            cur->left = NULL;
            cur->right = NULL;
            return cur;
        }
        if (left>right) {
            return NULL;
        }
        int midle = -1;
        cur->val = postorder[pos];
        for(int i = left; i <= right; i++){
            if (inorder[i]==postorder[pos]) {
                midle = i;
                break;
            }
        }
        cur->left = doBuild(left,midle-1,pos-(right-midle)-1,inorder,postorder);
        cur->right = doBuild(midle+1,right,pos-1,inorder,postorder);
        return cur;
    }
};
