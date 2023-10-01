class Solution:
    def myPow(self, x: float, n: int) -> float:
        # return x**n
        neg = n < 0
        if neg: n = -n
        res = 1
        while n > 0:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        if neg: res = 1 / res
        return res