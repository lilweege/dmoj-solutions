class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                if abs(nums[i]-nums[j]) == k:
                    ans += 1
        return ans