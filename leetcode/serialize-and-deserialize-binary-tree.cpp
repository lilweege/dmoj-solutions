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
    #define delim 32

    string encodeVal(int val) {
        // 11 bits <= 16 bits (two chars)
        // printable ascii because might as well use extra space
        val += 1000;
        string s = "";
        s += val / 93 + 33;
        s += val % 93 + 33;
        return s;
    }

    int decodeVal(const string& s, int i) {
        return (s[i]-33)*93 + (s[i+1]-33) - 1000;
    }
    
    void dfs(string& s, TreeNode* node) {
        if (!node) return;
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
        int i = 0;
        TreeNode* root = new TreeNode(decodeVal(s, 0));
        TreeNode* curr = root;
        stack<TreeNode*> st;
        st.push(curr);
        bool goRight = false;
        for (int i = 2; i < s.size(); i += 2) {
            if (s[i] == delim) {
                curr = st.top(); st.pop();
                goRight = true;
                // i -> i-1+2 = i+1
                --i;
                continue;
            }
            TreeNode* nxt = new TreeNode(decodeVal(s, i));
            st.push(nxt);
            if (goRight)
                curr->right = nxt;
            else curr->left = nxt;
            goRight = false; 
            curr = nxt;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));