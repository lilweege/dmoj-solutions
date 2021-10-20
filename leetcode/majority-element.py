// https://leetcode.com/problems/majority-element

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        cnt = {}
        for num in nums:
            if num not in cnt:
                cnt[num] = 0
            cnt[num] += 1
        
        for num, appearTimes in cnt.items():
            if appearTimes > n/2:
                return num
        return -1