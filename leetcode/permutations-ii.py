// https://leetcode.com/problems/permutations-ii

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
            perms = []
            n = len(nums)
            def dfs(i=0):
                if i == n-1:
                    if nums not in perms:
                        perms.append(nums.copy())
                    return

                for j in range(i, n):
                    nums[i], nums[j] = nums[j], nums[i]
                    dfs(i+1)
                    nums[i], nums[j] = nums[j], nums[i]

            dfs()
            return perms