def bs(lo, hi, pred):
    while lo < hi:
        mid = (lo + hi) // 2
        if pred(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

class Solution:
    def twoEggDrop(self, n: int) -> int:
        ok = lambda x: x * (x+1) // 2 >= n
        return bs(1, n, ok)