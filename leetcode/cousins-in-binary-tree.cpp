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
    bool isCousins(TreeNode* root, int x, int y) {
        deque<TreeNode*> q; q.push_back(root);
        while (!q.empty()) {
            
            TreeNode* parentX = nullptr, * parentY = nullptr;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front(); q.pop_front();
                if (node->left) {
                    q.push_back(node->left);
                    if (node->left->val == x) parentX = node;
                    if (node->left->val == y) parentY = node;
                }
                if (node->right) {
                    q.push_back(node->right);
                    if (node->right->val == x) parentX = node;
                    if (node->right->val == y) parentY = node;
                }
            }
            
            if (parentX && parentY) // found both same depth
                return parentX != parentY;
            else if (parentX != parentY) // found only one
                return false;
        }
        return false;
        
    }
};