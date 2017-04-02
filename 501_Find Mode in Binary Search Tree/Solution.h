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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int cnt = 0;
        unordered_map<int,int> mm;
        dfs(root,cnt,mm);
        for( pair<int,int> p : mm ){
            if( p.second == cnt ){
                res.push_back(p.first);
            }
        }
        return res;
    }
private:
    void dfs(TreeNode* root,int& cnt,unordered_map<int,int>& mm){
        if( root == NULL ){
            return ;
        }
        mm[root->val]++;
        cnt = max(mm[root->val],cnt);
        dfs(root->left,cnt,mm);
        dfs(root->right,cnt,mm);
        return ;
    }
};
