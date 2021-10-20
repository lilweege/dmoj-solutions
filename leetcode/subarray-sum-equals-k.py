// https://leetcode.com/problems/subarray-sum-equals-k

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sumFreq = { 0: 1 }
        run = 0
        cnt = 0
        
        for num in nums:
            run += num
            if run - k in sumFreq:
                cnt += sumFreq[run - k]
            
            if run not in sumFreq:
                sumFreq[run] = 0
            sumFreq[run] += 1

        return cnt