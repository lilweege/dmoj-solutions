// https://leetcode.com/problems/binary-tree-preorder-traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root):
        if root:
            self.ans.append(root.val)
            self.dfs(root.left)
            self.dfs(root.right)
        
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        self.ans = []
        self.dfs(root)
        return self.ans