class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        dct = set(dictionary)
        n = len(s)
        ans = n
        best = {}
        def dfs(i, x):
            nonlocal ans
            if i in best and best[i] <= x:
                return
            best[i] = x
            ans = min(ans, x+n-i)
            if i == n:
                return
            for j in range(i, n+1):
                if s[i:j] in dct:
                    dfs(j, x)
                dfs(j, x+j-i)

        dfs(0, 0)
        return ans