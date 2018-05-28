Use map to record numbers of prefix.
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
    int pathSum(TreeNode* root, int sum) {
        map<int, int> prefix;
        prefix[0] = 1;
        int res = dfs(root, prefix, 0, sum);
        return res;
    }
private:
    int dfs(TreeNode* node, map<int,int>& prefix, int cursum, int sum){
        if (node == NULL) {
            return 0;
        }
        cursum += node->val;
        int res = prefix[cursum-sum];
        prefix[cursum] += 1;
        res += dfs(node->left, prefix, cursum, sum)+dfs(node->right, prefix, cursum, sum);
        prefix[cursum] -= 1;
        return res;
    }
};
```
