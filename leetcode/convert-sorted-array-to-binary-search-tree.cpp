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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
    
    TreeNode* build(const vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* c = new TreeNode(nums[m]);
        c->left = build(nums, l, m-1);
        c->right = build(nums, m+1, r);
        return c;
    }
};