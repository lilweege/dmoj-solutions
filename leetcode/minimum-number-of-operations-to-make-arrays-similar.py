class Solution:
    def makeSimilar(self, nums: List[int], target: List[int]) -> int:
        evenNums = sorted(x//2 for x in nums if x % 2 == 0)
        oddNums = sorted(x//2 for x in nums if x % 2 != 0)
        evenTarget = sorted(x//2 for x in target if x % 2 == 0)
        oddTarget = sorted(x//2 for x in target if x % 2 != 0)

        def ans(a, b):
            return sum(x-y for x, y in zip(a, b) if x > y)

        return ans(evenNums, evenTarget) + ans(oddNums, oddTarget)