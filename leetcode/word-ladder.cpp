// https://leetcode.com/problems/word-ladder

// as usual this sucks

class Solution {
public:
    
    bool offByOne(const string& a, const string& b) {
        int n = a.size();
        int d = 0;
        for (int i = 0; i < n; ++i)
            if ((d += (a[i] != b[i])) == 2)
                return false;
        return d == 1;
    }
    
    struct Node {
        string val;
        vector<Node*> child;
        bool vis;
    };
    
    
    void createTree(Node* root, const vector<Node*>& nodes) {
        root->vis = true;
        for (Node* node : nodes)
            if (node != root && offByOne(root->val, node->val))
                root->child.push_back(node);
        for (Node* child : root->child)
            if (!child->vis)
                createTree(child, nodes);
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        Node* root = new Node();
        root->val = beginWord;
        
        int n = wordList.size();
        vector<Node*> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node();
            nodes[i]->val = wordList[i];
        }
        
        createTree(root, nodes);
        
        unordered_set<Node*> vis;
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            queue<Node*> level;
            while (!q.empty()) {
                level.push(q.front()); q.pop();
            }
            ++depth;

            while (!level.empty()) {
                Node* node = level.front(); level.pop();
                // cout << node->val << "\n";
                if (node->val == endWord)
                    return depth;
                if (vis.find(node) != vis.end())
                    continue;
                vis.insert(node);
                
                // cout << node->child.size() << "\n";
                for (Node* child : node->child)
                    q.push(child);
            }
        }
        
        // cout << "impossible\n";
        return 0;
    }
};