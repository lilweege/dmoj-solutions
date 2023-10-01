class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        ans = sorted(enumerate(mat), key=lambda tup: (sum(tup[1]), tup[0]))
        return [idx for (idx, row) in ans[:k]]