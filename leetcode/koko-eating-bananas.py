class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        ok = lambda x: sum(ceil(a / x) for a in piles) <= h

        lo, hi = 1, max(piles)
        while lo < hi:
            mid = (lo + hi) // 2
            if ok(mid):
                hi = mid
            else:
                lo = mid + 1

        return lo