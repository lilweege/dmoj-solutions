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
    bool isValidBST(TreeNode* node, long lo=LONG_MIN, long hi=LONG_MAX) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi)
            return false;
        return isValidBST(node->left, lo, node->val) && isValidBST(node->right, node->val, hi);
    }
};