// https://leetcode.com/problems/diameter-of-binary-tree

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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL)
            return { 0, 0 };
        
        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);
        
        int diam = max(max(l.first, r.first), l.second + r.second);
        int dept = max(l.second, r.second) + 1;
        
        return { diam, dept };
    }
};