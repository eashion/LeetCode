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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        vector<int> path;
        dfs(root, sum, path, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int sum, vector<int> path, vector<vector<int>>& res){
        if (node->left==NULL && node->right==NULL) {
            if (sum == node->val) {
                path.push_back(sum);
                res.push_back(path);
                path.pop_back();
            }
            return ;
        }
        path.push_back(node->val);
        if (node->left != NULL) 
            dfs(node->left, sum-node->val, path, res);
        if (node->right != NULL) 
            dfs(node->right, sum-node->val, path, res);
        path.pop_back();
        return ;
    }
};
```
