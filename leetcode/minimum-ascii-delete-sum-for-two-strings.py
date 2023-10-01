class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:

        @cache
        def lev(a, b):
            if len(a) == 0: return sum(ord(c) for c in b)
            if len(b) == 0: return sum(ord(c) for c in a)
            if a[0] == b[0]: return lev(a[1:], b[1:])
            return min(
                ord(a[0]) + lev(a[1:], b),
                ord(b[0]) + lev(a, b[1:]),
            )
        return lev(s1, s2)
