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
    unordered_map<int, int> idx;
    vector<int> preorder;
    int i = 0;
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int x = preorder[i++];
        int m = idx[x];
        return new TreeNode(x,
            build(l, m-1),
            build(m+1, r));
    }
public:
    TreeNode* buildTree(vector<int>& preorder_, vector<int>& inorder) {
        preorder = move(preorder_);
        int n = inorder.size();
        for (int j = 0; j < n; ++j)
            idx[inorder[j]] = j;
        return build(0, n-1);
    }
};