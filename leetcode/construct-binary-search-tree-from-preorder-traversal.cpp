// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    void insert(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* prev = root;
        while (cur) {
            prev = cur;
            if (val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (val < prev->val)
            prev->left = new TreeNode(val);
        else
            prev->right = new TreeNode(val);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
            insert(root, preorder[i]);
        return root;
    }
};
