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
    int longestUnivaluePath(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        int res = 0;
        findPath(root,root->val-1,res);
        return res-1;
    }
private:
    int findPath(TreeNode* node,int lastVal,int &res){
        int left = 0;
        int right = 0;
        int total = 0;
        if (node->left!=NULL) {
            left = findPath(node->left,node->val,res);
        }
        if (node->right!=NULL) {
            right = findPath(node->right,node->val,res);
        }
        if (node->left!=NULL && node->right!=NULL) {
            if (node->val!=lastVal) {
                total = left+right+1;
                res = max(res,total);
                return 0;
            } else {
                total = 1+max(left,right);
                return total;
            }
        } else if (node->left!=NULL) {
            if (node->val!=lastVal) {
                total = left+1;
                res = max(res,total);
                return 0;
            } else {
                total = 1+left;
                return total;
            }
        } else if (node->right!=NULL) {
            if (node->val!=lastVal) {
                total = right+1;
                res = max(res,total);
                return 0;
            } else {
                total = 1+right;
                return total;
            }
        } else {
            if (node->val!=lastVal) {
                res = max(res,1);
                return 0;
            } else {
                return 1;
            }
        }
    }
};

class Solution {
    public int longestUnivaluePath(TreeNode root) {
        int[] res = new int[1];
        if (root != null) dfs(root, res);
        return res[0];
    }

    private int dfs(TreeNode node, int[] res) {
        int l = node.left != null ? dfs(node.left, res) : 0;
        int r = node.right != null ? dfs(node.right, res) : 0;
        int resl = node.left != null && node.left.val == node.val ? l + 1 : 0;
        int resr = node.right != null && node.right.val == node.val ? r + 1 : 0;
        res[0] = Math.max(res[0], resl + resr);
        return Math.max(resl, resr);
    }
}
