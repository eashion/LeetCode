struct node{
    int val;
    int x,y;
    node(int x,int y,int val){
        this->x = x;
        this->y = y;
        this->val = val;
    }
    bool operator < (node a) const{
        return this->val>a.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node, vector<node>> max_heap;
        max_heap.push(node(0,0,matrix[0][0]));
        int flag = matrix[0][0]-1;
        int cnt = 0;
        while(cnt<k-1){
            node cur = max_heap.top();
            max_heap.pop();
            cnt++;
            int px = cur.x+1;
            if (px<matrix.size() && matrix[px][cur.y]!=flag) {
                max_heap.push(node(px,cur.y,matrix[px][cur.y]));
                matrix[px][cur.y]=flag;
            }
            int py = cur.y+1;
            if (py<matrix[0].size() && matrix[cur.x][py]!=flag) {
                max_heap.push(node(cur.x,py,matrix[cur.x][py]));
                matrix[cur.x][py]=flag;
            }
        }
        node top = max_heap.top();
        return top.val;
    }
};

struct node{
    int val;
    int x,y;
    node(int x,int y,int val){
        this->x = x;
        this->y = y;
        this->val = val;
    }
    bool operator < (node a) const{
        return this->val>a.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node, vector<node>> max_heap;
        for (int i = 0; i < matrix.size(); i++) {
            max_heap.push(node(i,0,matrix[i][0]));
        }
        int cnt = 0;
        while(cnt<k-1){
            node cur = max_heap.top();
            max_heap.pop();
            cnt++;
            int py = cur.y+1;
            if (py<matrix[0].size()) {
                max_heap.push(node(cur.x,py,matrix[cur.x][py]));
            }
        }
        node top = max_heap.top();
        return top.val;
    }
};
