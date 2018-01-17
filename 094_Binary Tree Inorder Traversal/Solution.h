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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) {
            return res;
        }
        stack<TreeNode*> sta;
        sta.push(root);
        while (!sta.empty()) {
            TreeNode* cur = sta.top();
            sta.pop();
            if (cur->left==NULL && cur->right==NULL) {
                res.push_back(cur->val);
                continue;
            }
            if (cur->right!=NULL){
                sta.push(cur->right);
                cur->right = NULL;
            }
            sta.push(cur);
            if (cur->left!=NULL) {
                sta.push(cur->left);
                cur->left = NULL;
            }
        }
        return res;
    }
};

public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> list = new ArrayList<Integer>();

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode cur = root;

    while(cur!=null || !stack.empty()){
        while(cur!=null){
            stack.add(cur);
            cur = cur.left;
        }
        cur = stack.pop();
        list.add(cur.val);
        cur = cur.right;
    }

    return list;
}
