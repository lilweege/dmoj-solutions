class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        return (all(x >= y for x, y in pairwise(nums)) or
                all(x <= y for x, y in pairwise(nums)))
        # inc = dec = True
        # for x, y in pairwise(nums):
        #     inc &= x <= y
        #     dec &= x >= y
        # return inc or dec
