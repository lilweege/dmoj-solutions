# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append((root, 0))

        best = 0
        while q:
            mi = min(x[1] for x in q)
            b, q = q, deque()
            levelmin, levelmax = int(1e9), int(-1e9)
            while b:
                x, pos = b.popleft()
                pos -= mi
                levelmin = min(levelmin, pos)
                levelmax = max(levelmax, pos)
                if x.left:
                    q.append((x.left, 2*pos + 1))
                if x.right:
                    q.append((x.right, 2*pos + 2))
            best = max(best, levelmax-levelmin)
        return best+1