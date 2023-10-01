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
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return { 0, INT_MIN };
        
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int left = max(0, l.first);
        int right = max(0, r.first);
        
        return {
            root->val + max(left, right),
            max(max(l.second, r.second), left + root->val + right),
        };
    }
public:
    int maxPathSum(TreeNode* root) {
        auto x = dfs(root);
        return max(x.first, x.second);
    }
};