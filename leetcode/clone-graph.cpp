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
    unordered_map<Node*, Node*> mm;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        auto it = mm.find(node);
        if (it != mm.end()) return it->second;
        Node* newNode = new Node(node->val);
        mm[node] = newNode;
        for (Node* neigh : node->neighbors) {
            Node* child = cloneGraph(neigh);
            if (child)
                newNode->neighbors.push_back(child);
        }
        return newNode;
    }
};