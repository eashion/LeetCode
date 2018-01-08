class NumArray {
private:
struct Node{
    int left = -1;
    int right = -1;
    int sum = 0;
    Node* leftNode = NULL;
    Node* rightNode = NULL;
};

Node* root;
void buildTree(Node* &node,int left,int right,vector<int> nums){
    if (left==right) {
        node->left = left;
        node->right= right;
        node->sum = nums[left];
        return ;
    }
    node->left = left;
    node->right = right;
    int mid = (left+right)>>1;
    Node* leftNode = new Node();
    buildTree(leftNode,left,mid,nums);
    Node* rightNode = new Node();
    buildTree(rightNode,mid+1,right,nums);
    node->leftNode = leftNode;
    node->rightNode = rightNode;
    node->sum = leftNode->sum+rightNode->sum;
    return ;
}
int findSum(Node* node,int left,int right){
    if (node->left==left && node->right==right) {
        return node->sum;
    }
    int mid = (node->left+node->right)>>1;
    if (right<=mid) {
        return findSum(node->leftNode,left,right);
    } else if (left>=mid+1) {
        return findSum(node->rightNode,left,right);
    } else {
        return findSum(node->leftNode,left,mid)+findSum(node->rightNode,mid+1,right);
    }
}
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        Node *node = new Node();
        if (len==0) {
            node = NULL;
        } else {
            buildTree(node,0,len-1,nums);
        }
        root = node;
    }
    
    int sumRange(int i, int j) {
        return findSum(root,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};
