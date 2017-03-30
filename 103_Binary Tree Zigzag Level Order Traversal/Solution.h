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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( root == NULL ){
            return res;
        }
        vector<TreeNode*> parents;
        vector<TreeNode*> children;
        children.push_back(root);
        int type = 0;
        while( true ){
            vector<int> tmp;
            if( type == 0 ){
                type = 1;
                for( int i = 0; i < children.size(); i++ ){
                    tmp.push_back(children[i]->val);
                }
            }
            else{
                type = 0;
                for( int i = children.size()-1; i >= 0; i-- ){
                    tmp.push_back(children[i]->val);
                }
            }
            if( tmp.size() == 0 ){
                break;
            }
            res.push_back(tmp);
            for( int i = 0; i < children.size(); i++ ){
                parents.push_back(children[i]);
            }
            children.clear();
            for( int i = 0; i < parents.size(); i++ ){
                if( parents[i]->left != NULL ){
                    children.push_back(parents[i]->left);
                }
                if( parents[i]->right != NULL ){
                    children.push_back(parents[i]->right);
                }
            }
            parents.clear();
        }
        return res;
    }
};
