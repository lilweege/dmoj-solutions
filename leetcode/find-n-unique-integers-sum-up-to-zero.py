// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution:
    def sumZero(self, n: int) -> List[int]:
        return range(1-n, n, 2)