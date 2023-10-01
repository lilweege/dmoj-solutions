struct Node {
    int i;
    vector<Node*> children;
    Node(int _i) : i(_i) {}
};

class Solution {
    vector<string> ans;
    vector<Node*> ends;

    Node* traverse(const string& s, const unordered_set<string>& dict, size_t i=0) {
        int n = s.size();
        if (i == n) {
            Node* end = new Node(i);
            ends.push_back(end);
            return end;
        }
        Node* node = i == 0 ? nullptr : new Node(i);
        for (int j = 1; j <= n-i; ++j)
            if (dict.find(s.substr(i, j)) != dict.end()) {
                Node* nxt = traverse(s, dict, i+j);
                if (nxt)
                    nxt->children.push_back(node);
            }
        return node;
    }
    
    void reconstruct(const string& orig, string& sep, Node* root) {
        if (!root) {
            ans.push_back(sep);
            sep = orig;
            return;
        }
        if (root->i != orig.size())
            sep.insert(root->i, 1, ' ');
        for (Node* child : root->children) {
            reconstruct(orig, sep, child);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (const auto& word : wordDict)
            dict.insert(word);
        
        ans.clear();
        ends.clear();
        traverse(s, dict);
        string bruh = s;
        for (Node* end : ends)
            reconstruct(s, bruh, end);
        
        return ans;
    }
};