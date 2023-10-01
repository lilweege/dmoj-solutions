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
    int ans;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto [cnt1, sum1] = dfs(root->left);
        auto [cnt2, sum2] = dfs(root->right);
        int cnt = cnt1 + cnt2 + 1;
        int sum = sum1 + sum2 + root->val;
        if (sum / cnt == root->val)
            ++ans;
        return {cnt, sum};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};