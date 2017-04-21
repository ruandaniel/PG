/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m; //make a mapping in case of repeating
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        if (m.count(node) == 0){ //if it's a new node, make a new mapping and also clone neighbors
            m[node] = new UndirectedGraphNode(node->label);
            for (auto i : node->neighbors){
                m[node]->neighbors.push_back(cloneGraph(i)); //here not i but cloneGraph(i);
            }
        }
        return m[node];
    }
};