Since there maybe exist a self loop, so we need to use map to bind label with pointer.
```
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    map<int, UndirectedGraphNode*> mm;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        //printf("node: %d\n",node->label);
        if (mm.find(node->label) != mm.end()) {
            return mm[node->label];
        }
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        mm[node->label] = newNode;
        vector<UndirectedGraphNode*> neighList;
        //printf("size: %d\n", node->neighbors.size());
        for(int i = 0; i < node->neighbors.size(); i++){
            neighList.push_back(cloneGraph(node->neighbors[i]));
        }
        newNode->neighbors = neighList;
        return newNode;
    }
};
```
