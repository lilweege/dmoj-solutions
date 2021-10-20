// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    TreeNode* search(TreeNode* head, TreeNode* target)
    {
        TreeNode *l, *r;
        if (head->left)
        {
            l = search(head->left, target);
            if (l && l->val == target->val)
                return l;
        }
        if (head->right)
        {
            r = search(head->right, target);
            if (r && r->val == target->val)
                return r;
        }
        
        if (head->val == target->val)
            return head;
        return nullptr;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return search(cloned, target);
    }
};