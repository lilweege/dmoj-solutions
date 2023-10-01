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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (!root) return levels;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> b;
            q.swap(b);
            levels.emplace_back();
            auto& breadth = levels.back();
            while (!b.empty()) {
                TreeNode* curr = b.front(); b.pop();
                breadth.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return levels;
    }
};