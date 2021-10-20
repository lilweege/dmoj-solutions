// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    vector<int> inorder;
    void inorder_traverse(TreeNode* node) {
        if (!node)
            return;
        inorder_traverse(node->left);
        inorder.push_back(node->val);
        inorder_traverse(node->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder_traverse(root);
        return inorder[k - 1];
    }
};