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
    int target;
    int cnt;
    unordered_map<long long, int> mm;

    void dfs(TreeNode* node, long long sum = 0) {
        if (node == nullptr) return;
        sum += node->val;
        cnt += mm[sum-target];
        ++mm[sum];
        dfs(node->left, sum);
        dfs(node->right, sum);
        --mm[sum];
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        mm[0] = 1;
        target = targetSum;
        cnt = 0;
        dfs(root);
        return cnt;
    }
};