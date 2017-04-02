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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        dfs(root,p,q,res);
        return res;
    }
private:
    bool dfs(TreeNode* cur,TreeNode* p,TreeNode* q,TreeNode*& res){
        if( cur == NULL ){
            return false;
        }
        bool f1,f2,f3;
        f1 = false;
        f2 = false;
        f3 = false;
        if( cur==p || cur==q ){
            f3 = true;
        }
        f1 = dfs(cur->left,p,q,res);
        f2 = dfs(cur->right,p,q,res);
        if( f1 && f2 ){
            res = cur;
            //cout<<cur->val<<"type1"<<endl;
            return false;
        }
        if( f1 && f3 ){
            res = cur;
            //cout<<cur->val<<"type2"<<endl;
            return false;
        }
        if( f2 && f3 ){
            res = cur;
            //cout<<cur->val<<"type3"<<endl;
            return false;
        }
        if( f1 || f2 || f3 ){
            return true;
        }
        return false;
    }
};
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res;
        if( p->val < root->val && q->val < root->val ){
            res = lowestCommonAncestor(root->left,p,q);
        }
        else if( p->val > root->val && q->val > root->val ){
            res = lowestCommonAncestor(root->right,p,q);
        }
        else{
            res = root;
        }
        return res;
    }
};
