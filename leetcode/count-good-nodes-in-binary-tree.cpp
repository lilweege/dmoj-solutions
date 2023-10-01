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
public:
    int goodNodes(TreeNode* root, int maxVal=INT_MIN) {
        if (!root) return 0;
        int newMax = max(maxVal, root->val);
        return (root->val >= maxVal) +
            goodNodes(root->left, newMax) +
            goodNodes(root->right, newMax);
    }
};