/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = nullptr;
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return 0;
        int yes = dfs(node->left, p, q) | dfs(node->right, p, q);
        if (node == p) yes |= 0b01;
        if (node == q) yes |= 0b10;
        if (!ans && yes == 0b11) ans = node;
        return yes;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};