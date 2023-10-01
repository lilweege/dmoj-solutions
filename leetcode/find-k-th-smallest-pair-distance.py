
def bisect_predicate(lo, hi, pred):
    while lo < hi:
        mi = (lo + hi) // 2
        if pred(mi):
            lo = mi + 1
        else:
            hi = mi
    return lo


def solve(L, i):
    n = len(L)
    L = sorted(L)

    def count_at_most(x):
        """Count the number of pairs with absolute difference of at most x"""
        # Compute the index k of the first number larger than L[j] + x
        # Every pair difference from L[j+1:k] - L[j] is at most x
        # Add these counts for every pair starting with L[j] for all j
        cnt = 0
        k = 0
        for j in range(n):
            while k < n and L[k] - L[j] <= x:
                k += 1
            cnt += (k - 1) - j
        return cnt

    # Binary search on the 'too_few' predicate to find the first value for
    # which the number of pairs with difference of at most x isn't less than i.
    lo, hi = 0, L[n-1] - L[0]
    too_few = lambda x: count_at_most(x) < i
    return bisect_predicate(lo, hi, too_few)


class Solution:
    def smallestDistancePair(self, lst: List[int], K: int) -> int:
        return solve(lst, K)