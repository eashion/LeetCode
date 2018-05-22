one simple way is use queue to replace the 2-dimention vector. do for loop in while loop
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        int flag = 0;
        vector<vector<TreeNode*>> nodes(2, vector<TreeNode*>());
        nodes[flag].push_back(root);
        while(nodes[flag].size()!=0){
            vector<int> cur;
            int next = (flag+1)%2;
            for(int i = 0; i < nodes[flag].size(); i++){
                cur.push_back(nodes[flag][i]->val);
                if (nodes[flag][i]->left != NULL) 
                    nodes[next].push_back(nodes[flag][i]->left);
                if (nodes[flag][i]->right != NULL) 
                    nodes[next].push_back(nodes[flag][i]->right);
            }
            nodes[flag].clear();
            flag = next;
            res.push_back(cur);
        }
        return res;
    }
};
```
