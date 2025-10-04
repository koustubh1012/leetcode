/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> graph;
        Node* new_node = clone(node, graph);
        return new_node;
    }

    Node* clone(Node* node, unordered_map<Node*, Node*>& graph){
        if(graph.find(node) != graph.end()) return graph[node];

        Node* copy = new Node(node->val);
        graph[node] = copy;

        for(auto neighbor : node->neighbors){
            copy->neighbors.push_back(clone(neighbor, graph));
        }

        return copy;
    }
};
