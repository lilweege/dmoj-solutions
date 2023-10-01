class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        aa = sorted(cnt.items(), key=lambda x: (-x[1], x[0]))
        return [x for x,y in aa[:k]]
