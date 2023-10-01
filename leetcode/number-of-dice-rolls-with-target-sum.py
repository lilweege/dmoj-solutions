
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        @cache
        def roll(n, m):
            if n == 1: return 1 if 1<=m<=k else 0
            return sum(roll(n-1, m-i) for i in range(1, k+1)) % int(1e9+7)
        return roll(n, target)