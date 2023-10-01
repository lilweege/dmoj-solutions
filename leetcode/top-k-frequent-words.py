from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        ans = []
        cnt = Counter(words)
        sorte = sorted(list(cnt.items()), key=lambda x: (-x[1], x[0]), reverse=True)
        n = len(sorte)
        return list(reversed([sorte[i][0] for i in range(n-k, n)]))
