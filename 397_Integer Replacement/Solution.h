#The easiest way to solve this problem is bfs, find the shortest move. But it can be a little inefficient.
#Or we can do it with greedy. Our target is remove the digits to 1. We can only remove digits when num is even.
#So our job is remove as many 1 as possible with num+1 or num-1. And it depends on the last three digits of num.
class Solution {
    public int integerReplacement(int n) {
        int c = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                n >>>= 1;
            } else if (n == 3 || ((n >>> 1) & 1) == 0) {
                --n;
            } else {
                ++n;
            }
            ++c;
        }
        return c;
    }
}

struct Node{
    long num;
    int cnt;
    Node(){}
    Node(long num, int cnt){
        this->num = num;
        this->cnt = cnt;
    }
};
class Solution {
public:
    int integerReplacement(int n) {
        queue<Node> que;
        Node root = Node(n, 0);
        que.push(root);
        int res = 0;
        while(!que.empty()){
            Node cur = que.front();
            que.pop();
            if (cur.num==1) {
                res = cur.cnt;
                break;
            }
            if (cur.num%2==0) {
                if (cur.num==2) {
                    res = cur.cnt+1;
                    break;
                }
                que.push(Node(cur.num/2, cur.cnt+1));
            } else {
                que.push(Node((long)cur.num+1, cur.cnt+1));
                que.push(Node(cur.num-1, cur.cnt+1));
            }
        }
        return res;
    }
};
