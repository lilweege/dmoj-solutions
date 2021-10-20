// https://leetcode.com/problems/permutations

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        perms = []
        n = len(nums)
        def dfs(i=0):
            if i == n-1:
                perms.append(nums.copy())
                return

            for j in range(i, n):
                nums[i], nums[j] = nums[j], nums[i]
                dfs(i+1)
                nums[i], nums[j] = nums[j], nums[i]

        dfs()
        return perms