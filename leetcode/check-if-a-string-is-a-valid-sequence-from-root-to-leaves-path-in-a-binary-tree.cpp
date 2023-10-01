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
    // valid, depth
    bool dfs(TreeNode* root, int depth, vector<int>& arr) {
        if (depth == arr.size() - 1)
            return !(root->left || root->right);
    
        bool left = false, right = false;
        if (root->left && root->left->val == arr[depth + 1])
            left = dfs(root->left, depth + 1, arr);
        if (root->right && root->right->val == arr[depth + 1])
            right = dfs(root->right, depth + 1, arr);
        
        return left || right;
    }
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, 0, arr);
    }
};