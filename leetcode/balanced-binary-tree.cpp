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
    bool ok = true;
    int dfs(TreeNode* node, int dep=0) {
        if (!node) return dep;
        int l = dfs(node->left, dep+1);
        int r = dfs(node->right, dep+1);
        ok &= abs(l - r) <= 1;
        return max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ok;
    }
};