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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        que.push(root);
        int num1 = 1;
        int cnt = 0;
        double sum = 0;
        while(!que.empty()){
            TreeNode* cur = que.front();
            que.pop();
            cnt++;
            sum += cur->val;
            if (cur->left!=NULL) {
                que.push(cur->left);
            }
            if (cur->right!=NULL) {
                que.push(cur->right);
            }
            if (cnt==num1) {
                res.push_back(sum/num1);
                num1 = que.size();
                cnt = 0;
                sum = 0;
            }
        }
        return res;
    }
};
