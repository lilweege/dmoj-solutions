// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top(); st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return ans;
    }
};