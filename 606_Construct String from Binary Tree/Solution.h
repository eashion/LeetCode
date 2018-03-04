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
    string tree2str(TreeNode* t) {
        string res = traversal(t);
        string ope = "";
        for(int i = 0; i < res.length(); i++){
            if (res[i]=='(') {
                if (res[i-1]==')' && res[i+1]==')') {
                    i++;
                    continue;
                } else {
                    ope += res[i];
                }
            } else {
                ope += res[i];
            }
        }
        cout<<ope<<endl;
        return ope;
    }
private:
    string traversal(TreeNode* node){
        if (node == NULL) {
            return "";
        }
        if (node->left==NULL && node->right==NULL) {
            return to_string(node->val);
        }
        return to_string(node->val)+"("+traversal(node->left)+")"+"("+traversal(node->right)+")";
    }
};
