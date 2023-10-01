class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        n = len(bombs)
        adj = [[] for _ in range(n)]
        for i in range(n):
            x1, y1, r1 = bombs[i]
            for j in range(n):
                x2, y2, r2 = bombs[j]
                if dist((x1, y1), (x2, y2)) <= r1:
                    adj[i].append(j)

        vis = set()
        def dfs(u):
            if u in vis: return
            vis.add(u)
            for v in adj[u]:
                dfs(v)

        longest = 0
        for s in range(n):
            vis.clear()
            dfs(s)
            longest = max(longest, len(vis))
        return longest