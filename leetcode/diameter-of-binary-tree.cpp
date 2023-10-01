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
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return { 0, 0 };
        auto [l_diam, l_dept] = dfs(node->left);
        auto [r_diam, r_dept] = dfs(node->right);
        int diam = max({ l_diam, r_diam, l_dept + r_dept });
        int dept = max(l_dept, r_dept) + 1;
        return { diam, dept };
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};