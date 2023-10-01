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
    void dfs(TreeNode* root, bool parEven=false, bool gparEven=false) {
        if (!root) return;
        if (gparEven) ans += root->val;
        bool isEven = root->val % 2 == 0;
        dfs(root->left, isEven, parEven);
        dfs(root->right, isEven, parEven);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};