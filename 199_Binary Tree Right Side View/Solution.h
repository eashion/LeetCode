#可以选择逐层遍历，空间开销会有点大
#可以选择优先从右子树开始遍历，每层只记录第一次到达的元素，即最右的元素
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        vector<TreeNode*> lis1;
        vector<TreeNode*> lis2;
        lis1.push_back(root);
        while(!lis1.empty()){
            res.push_back(lis1.back()->val);
            for(int i = 0; i < lis1.size(); i++){
                if (lis1[i]->left != NULL) 
                    lis2.push_back(lis1[i]->left);
                if (lis1[i]->right != NULL)
                    lis2.push_back(lis1[i]->right);
            }
            lis1.clear();
            for(int i = 0; i < lis2.size(); i++){
                lis1.push_back(lis2[i]);
            }
            lis2.clear();
        }
        return res;
    }
};

public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        rightView(root, result, 0);
        return result;
    }
    
    public void rightView(TreeNode curr, List<Integer> result, int currDepth){
        if(curr == null){
            return;
        }
        if(currDepth == result.size()){
            result.add(curr.val);
        }
        
        rightView(curr.right, result, currDepth + 1);
        rightView(curr.left, result, currDepth + 1);
        
    }
}
