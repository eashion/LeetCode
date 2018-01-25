class Solution {
private:
struct Node{
    int num1;
    int num2;
    int pos2;
    Node(int num1,int num2,int pos2){
        this->num1 = num1;
        this->num2 = num2;
        this->pos2 = pos2;
    }
};
    
struct cmp{  
    bool operator() ( Node*& a, Node*& b ){return a->num1+a->num2 > b->num1+b->num2;}  
};
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Node*,vector<Node*>,cmp> que;
        vector<pair<int,int>> res;
        if(nums1.size()==0 || nums2.size()==0 || k==0){
            return res;
        }
        for(int i = 0; i<nums1.size() && i<k; i++){
            Node* node = new Node(nums1[i],nums2[0],0);
            que.push(node);
        }
        while(k-- && !que.empty()){
            Node* node = que.top();
            que.pop();
            pair<int,int> pp(node->num1,node->num2);
            res.push_back(pp);
            if (node->pos2==nums2.size()-1) {
                continue;
            }
            que.push(new Node(node->num1,nums2[node->pos2+1],node->pos2+1));
        }
        return res;
    }
};
