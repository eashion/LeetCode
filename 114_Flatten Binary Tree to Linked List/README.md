Do it with recursion or recursively.
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
    void flatten(TreeNode* root) {
        TreeNode* superRoot = new TreeNode(-1);
        superRoot->left = NULL;
        TreeNode* prev = superRoot;
        stack<TreeNode*> sta;
        sta.push(root);
        while(!sta.empty()){
            TreeNode* cur = sta.top();
            sta.pop();
            prev->right = cur;
            //cout<<cur->val<<endl;
            while(cur != NULL){
                if (cur->right != NULL) 
                    sta.push(cur->right);
                cur->right = cur->left;
                cur->left = NULL;
                prev = cur;
                cur = cur->right;
            }
        }
        return ;
    }
};
```
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
    void flatten(TreeNode* root) {
        if (root == NULL) 
            return ;
        build(root);
        return ;
    }
private:
    TreeNode* build(TreeNode* node){
        //cout<<"node: "<<node->val<<endl;
        TreeNode* left = node->left;
        node->left = NULL;
        TreeNode* right = node->right;
        node->right = NULL;
        TreeNode* end = node;
        if (left != NULL) {
            //cout<<"left"<<endl;
            TreeNode* leftEnd = build(left);
            end->right = left;
            end = leftEnd;
        }
        if (right != NULL) {
            //cout<<"right"<<endl;
            TreeNode* rightEnd = build(right);
            end->right = right;
            end = rightEnd;
        }
        return end;
    }
};
```
