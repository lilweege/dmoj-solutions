/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    const static unsigned char delim = 127;
    string encodeVal(int val) {
        string s = "";
        s += val / 127;
        s += val % 127;
        return s;
    }
    int decodeVal(const string& s, size_t i) {
        return s[i]*127 + s[i+1];
    }
    
    void dfs(string& s, TreeNode* node) {
        if (node == nullptr) return;
        s += encodeVal(node->val);
        dfs(s, node->left);
        s += delim;
        dfs(s, node->right);
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        dfs(s, root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return nullptr;
        TreeNode* root = new TreeNode(decodeVal(s, 0));
        TreeNode* curr = root;
        stack<TreeNode*> st;
        st.push(curr);
        bool pop = false;
        for (int i = 2; i < s.size(); i += 2) {
            if (s[i] == delim) {
                curr = st.top(); st.pop();
                pop = true;
                // i -> i-1+2 = i+1
                --i;
                continue;
            }
            TreeNode* nxt = new TreeNode(decodeVal(s, i));
            st.push(nxt);
            (pop ? curr->right : curr->left) = nxt;
            pop = false;
            curr = nxt;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;