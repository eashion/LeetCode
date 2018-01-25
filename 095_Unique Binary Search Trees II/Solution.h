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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) {
            vector<TreeNode*> tmp;
            return tmp;
        }
        return doGenerate(1,n);
    }
private:
    vector<TreeNode*> doGenerate(int left,int right){
        vector<TreeNode*> list;
        if (left>right) {
            list.push_back(NULL);
            return list;
        }
        if (left==right) {
            TreeNode* node = new TreeNode(left);
            list.push_back(node);
            return list;
        }
        vector<TreeNode*> ltree;
        vector<TreeNode*> rtree;
        for(int i = left; i <= right; i++){
            ltree = doGenerate(left,i-1);
            rtree = doGenerate(i+1,right);
            for(int j = 0; j < ltree.size(); j++){
                for(int k = 0; k < rtree.size(); k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = ltree[j];
                    root->right = rtree[k];
                    list.push_back(root);
                }
            }
        }
        return list;
    }
};
