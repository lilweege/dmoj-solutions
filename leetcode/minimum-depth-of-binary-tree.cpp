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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int dep = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++dep;
            queue<TreeNode*> b;
            swap(q, b);
            while (!b.empty()) {
                TreeNode* cur = b.front(); b.pop();
                if (!cur->left && !cur->right)
                    return dep;
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return dep;
    }
};