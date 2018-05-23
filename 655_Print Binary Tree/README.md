This problem is a little complicate. The point is find the right position of nodes.
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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if (root == NULL) {
            return res;
        }
        int deep = 0;
        deep = findDeep(root);
        //printf("deep: %d\n\n",deep);
        int size = pow(2,deep)-1;
        for(int i = 0; i < deep; i++){
            vector<string> cur(size, "");
            res.push_back(cur);
        }
        //printf("size: %d\n\n",size);
        buildTree(root, size/2, size/2, 0, res);
        return res;
    }
private:
    int findDeep(TreeNode* node){
        if (node==NULL)
            return 0;
        return max(findDeep(node->left), findDeep(node->right))+1;
    }
    void buildTree(TreeNode* node, int pos, int base, int deep, vector<vector<string>>& res){
        //printf("val:%d\n", node->val);
        //printf("pos:%d\n", pos);
        //printf("base:%d\n", base);
        //printf("deep:%d\n\n", deep);
        res[deep][pos] = to_string(node->val);
        if (node->left != NULL) {
            buildTree(node->left, pos-(base/2)-1, base/2, deep+1, res);
        }
        if (node->right != NULL) {
            buildTree(node->right, pos+(base/2)+1, base/2, deep+1, res);
        }
        return ;
    }
};
```
