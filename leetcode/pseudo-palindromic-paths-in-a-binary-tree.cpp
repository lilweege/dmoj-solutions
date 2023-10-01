/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int cnt = 0;
    int charCnts[9] = {0};
    
    bool possible() {
        bool seenOdd = false;
        for (int i = 0; i < 9; ++i) {
            int x = charCnts[i];
            if (x & 1) {
                if (seenOdd)
                    return false;
                seenOdd = true;
            }
        }
        return true;
    }

    void dfs(TreeNode* node) {
        if (!node) return;
        ++charCnts[node->val-1];
        if (node->left == nullptr && node->right == nullptr) {
            if (possible()) {
                ++cnt;
            }
        }
        else {
            dfs(node->left);
            dfs(node->right);
        }
        --charCnts[node->val-1];
    }
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};