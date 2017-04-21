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
    int countNodes(TreeNode* root) {
        if( root == NULL ){
            return 0;
        }
        int height = 0;
        TreeNode* cur = root;
        while( cur != NULL ){
            cur = cur->left;
            height++;
        }
        if( height == 1 ){
            return 1;
        }
        int cnt = 0;
        bool flag = false;
        findEmpty(root,1,cnt,height,flag);
        return pow(2,height-1)-1+cnt;
    }
private:
    void findEmpty(TreeNode* root,int deep,int& cnt,int height,bool& flag){
        if( flag == true ){
            return;
        }
        if( deep == height-1 ){
            if( root->right != NULL ){
                cnt += 2;
            }
            else if( root->left != NULL ){
                cnt += 1;
                flag = true;
            }
            else{
                flag = true;
            }
            return ;
        }
        else{
            findEmpty(root->left,deep+1,cnt,height,flag);
            findEmpty(root->right,deep+1,cnt,height,flag);
        }
    }
};
class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};
