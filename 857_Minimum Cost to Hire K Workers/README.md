The first thing is to figure out sample examples. Make sure understand the problem statement clearly. Among K peoples, wage is depend on the
people with largest wage/quality. So there is a natural order of the ratio. Start from the K-th smallest ratio people. We can only choose 
people from people whose ratio is smaller than him. And once the ratio is settled, other peoples' wage = quality*ratio. In order to minimize 
the sum of wage. We choose k smallest quality. We can use a priority_queue to maintain k smallest quality.
```
struct Node{
    int quality;
    int wage;
    double ratio;
    Node(){}
    Node(int quality, int wage, double ratio){
        this->quality = quality;
        this->wage = wage;
        this->ratio = ratio;
    }
    bool operator < (const Node& a) const {
        return this->ratio < a.ratio;
    }
};
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        //quality = {3,1,10,10,1}, wage = {4,8,2,2,7}, K = 1;
        int len = quality.size();
        vector<Node> nodes;
        for(int i = 0; i < len; i++){
            double ratio = 1.0*wage[i]/quality[i];
            nodes.push_back(Node(quality[i],wage[i],ratio));
        }
        sort(nodes.begin(), nodes.end());
        double sum = 0.0;
        priority_queue<int> que;
        for(int i = 0; i < K; i++){
            sum += nodes[i].quality;
            que.push(nodes[i].quality);
        }
        double res = sum*nodes[K-1].ratio;
        for(int i = K; i < len; i++){
            sum += nodes[i].quality;
            que.push(nodes[i].quality);
            sum -= que.top();
            que.pop();
            res = min(res, sum*nodes[i].ratio);
        }
        return res;
    }
};
```
