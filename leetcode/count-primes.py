// https://leetcode.com/problems/count-primes

class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3: return 0
        lst = [1] * n
        lst[0] = lst[1] = 0
        m = 2
        while m * m < n:
            if lst[m] == 1:
                lst[m * m: n: m] = [0] *(1 + (n - m * m - 1) // m)
            m += 1 if m == 2 else 2
        return sum(lst)