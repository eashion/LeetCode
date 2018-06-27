Just want to use O(1) space complexity. Just seperate it to three cases: 1. use the current node, search if there is another node and the value 
is k-cur.val; 2. find two nodes in left tree; 3. find two nodes in right tree. So we need a search function.
```
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
    bool findTarget(TreeNode* root, int k) {
        //k = 14;
        return dfs(root, root, k);
    }
private:
    bool dfs(TreeNode* root, TreeNode* cur, int k){
        if (cur == NULL) {
            return false;
        }
        return search(root, cur, k-cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    bool search(TreeNode* root, TreeNode* cur, int val){
        if (root == NULL) {
            return false;
        }
        if (root->val==val && root!=cur) {
            return true;
        }
        return search(root->right, cur, val) || search(root->left, cur, val);
    }
};
```
