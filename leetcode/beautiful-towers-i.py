class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        best = 0
        for i, peak in enumerate(maxHeights):
            cnt = peak
            curPeak = peak
            for j in reversed(range(i)):
                curPeak = min(curPeak, maxHeights[j])
                cnt += curPeak
            curPeak = peak
            for j in range(i+1, n):
                curPeak = min(curPeak, maxHeights[j])
                cnt += curPeak

            best = max(best, cnt)
        return best