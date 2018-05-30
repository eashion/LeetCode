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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root==NULL) 
            return res;
        dfs(root,"",res);
        return res;
    }
private:
    void dfs(TreeNode* node, string cur, vector<string>& res){
        //cout<<"cur: "<<cur<<endl;
        if (node->left==NULL && node->right==NULL) {
            string tmp = cur+"->"+to_string(node->val);
            res.push_back(tmp.substr(2));
            return ;
        }
        if (node->left != NULL) 
            dfs(node->left, cur+"->"+to_string(node->val), res);
        if (node->right != NULL) 
            dfs(node->right, cur+"->"+to_string(node->val), res);
    }
};
```
