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
    int ans = -1;
    int k;
    void dfs(TreeNode* node) {
        if (!node) return;
        if (ans != -1) return;
        dfs(node->left);
        ++cnt;
        if (cnt == k)
            ans = node->val;
        dfs(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k_) {
        k = k_;
        dfs(root);
        return ans;
    }
};