def findLocalMaxima(arr):
    n = len(arr)
    mx = []
    if(arr[0] > arr[1]):
        mx.append(0)
    nexteq = False
    for i in range(1, n-1):
        if not nexteq and arr[i] == arr[i+1]:
            mx.append(i)
            nexteq = True
        elif nexteq and arr[i] != arr[i+1]:
            mx.append(i)
            nexteq = False
        if nexteq:
            continue
        if(arr[i-1] <= arr[i] >= arr[i + 1]):
            mx.append(i)
    if(arr[-1] > arr[-2]):
        mx.append(n-1)
    return mx 

class Solution:
    def bf(self, maxHeights: List[int]) -> int:
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

    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        n = len(maxHeights)
        if n <= 4:
            return self.bf(maxHeights)
        def leftScore(i):
            peak = maxHeights[i]
            cnt = peak
            curPeak = peak
            for j in reversed(range(i)):
                curPeak = min(curPeak, maxHeights[j])
                cnt += curPeak
            return cnt
        def rightScore(i):
            peak = maxHeights[i]
            cnt = 0
            curPeak = peak
            for j in range(i+1, n):
                curPeak = min(curPeak, maxHeights[j])
                cnt += curPeak
            return cnt
        def score(i):
            return leftScore(i) + rightScore(i)

        # cand = []
        # window = deque()
        # for i, x in enumerate(maxHeights):
        #     if not window:
        #         window.append(x)
        #         continue
        #     if window[0]


        # best = 0
        # return best
        # return max(score(i) for i in cand)
        # print(findLocalMaxima(maxHeights))
        # return 0
        mx = findLocalMaxima(maxHeights)
        # print(len(mx))
        return max(score(i) for i in mx)