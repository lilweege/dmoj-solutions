class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        from collections import defaultdict
        n = 10002
        vals = [0]*n
        for x in nums: vals[x] += x
        yes, ans = 0, 0
        for i in range(n):
            yes, ans = ans + vals[i], max(ans, yes)
        return ans