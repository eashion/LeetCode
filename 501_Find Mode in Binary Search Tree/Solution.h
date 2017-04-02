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
        set<int> lis;
        vector<int> res;
        int cnt = 0;
        unordered_map<int,int> mm;
        dfs(root,cnt,mm,lis);
        for( auto iter : lis ){
            if( mm[iter] == cnt ){
                res.push_back(iter);
            }
        }
        //cout<<cnt<<endl;
        //cout<<mm[2]<<endl;
        return res;
    }
private:
    void dfs(TreeNode* root,int& cnt,unordered_map<int,int>& mm,set<int>& lis){
        if( root == NULL ){
            return ;
        }
        lis.insert(root->val);
        mm[root->val]++;
        cnt = max(mm[root->val],cnt);
        dfs(root->left,cnt,mm,lis);
        dfs(root->right,cnt,mm,lis);
        return ;
    }
};
