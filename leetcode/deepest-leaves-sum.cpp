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
    int maxdep;
    int ans;
    void dfs(TreeNode* node, int dep=0) {
        if (!node) return;
        if (dep > maxdep) {
            maxdep = dep;
            ans = 0;
        }
        if (dep == maxdep)
            ans += node->val;

        dfs(node->left, dep+1);
        dfs(node->right, dep+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        maxdep = 0;
        ans = 0;
        dfs(root);
        return ans;
    }
};