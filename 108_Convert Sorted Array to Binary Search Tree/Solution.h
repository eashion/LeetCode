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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size()-1);
    }
private:
    TreeNode* recursive(vector<int> nums, int left, int right){
        if (left > right) {
            return NULL;
        }
        if (left==right) {
            return new TreeNode(nums[left]);
        }
        int mid = (left+right)/2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = recursive(nums, left, mid-1);
        cur->right = recursive(nums, mid+1, right);
        return cur;
    }
};
