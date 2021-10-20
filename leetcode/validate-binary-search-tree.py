// https://leetcode.com/problems/validate-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        INF = 10**10
        s = [(root, -INF, INF)]
        while s:
            node, left, right = s.pop()
            
            if node:
                if node.val <= left or node.val >= right:
                    return False
                
                s.append((node.left, left, node.val))
                s.append((node.right, node.val, right))

        
        return True