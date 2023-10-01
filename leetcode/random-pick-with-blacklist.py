def bsearch_predicate(lo, hi, pred):
    while lo <= hi:
        mi = (lo + hi) // 2
        if pred(mi):
            lo = mi + 1
        else:
            hi = mi - 1
    return hi


class Solution:

    def __init__(self, n: int, blacklist: List[int]):
        self.blacklist = sorted(blacklist)
        self.sz = n - len(blacklist)
        # for i in range(n - len(blacklist)):
        #     print(i, self.source(i))

    def source(self, r: int) -> int:
        return r + 1 + bsearch_predicate(
            0,
            len(self.blacklist)-1,
            lambda x: self.blacklist[x] <= r+x
        )

    def pick(self) -> int:
        return self.source(randrange(self.sz))


# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()