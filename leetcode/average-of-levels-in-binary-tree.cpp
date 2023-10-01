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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            queue<TreeNode*> b;
            swap(q, b);
            double tot = 0;
            int num = 0;
            while (!b.empty()) {
                TreeNode* cur = b.front(); b.pop();
                tot += cur->val;
                ++num;
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(tot / num);
        }
        return ans;
    }
};