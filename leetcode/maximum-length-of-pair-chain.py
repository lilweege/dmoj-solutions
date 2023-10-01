class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # n = len(pairs)
        # adj = [[] for _ in range(n)]
        # for i, (a, b) in enumerate(pairs):
        #     for j, (c, d) in enumerate(pairs):
        #         if b < c:
        #             adj[i].append(j)

        # vis = set()
        # order = []
        # def topsort(u):
        #     if u in vis: return
        #     vis.add(u)
        #     for v in adj[u]:
        #         topsort(v)
        #     order.append(u);

        # for i in range(n):
        #     topsort(i)

        # dist = [1]*n
        # while order:
        #     u = order.pop()
        #     for v in adj[u]:
        #         if dist[v] < dist[u] + 1:
        #             dist[v] = dist[u] + 1

        # return max(dist)



        # pairs.sort(key=lambda x: -x[1])
        # n = len(pairs)
        # dp = [1]*n
        # for i in range(1, n):
        #     a, b = pairs[i]
        #     be = 0
        #     for j in range(i):
        #         c, d = pairs[j]
        #         if b < c:
        #             be = max(be, dp[j])
        #     dp[i] = be + 1
        # return max(dp)



        n = len(pairs)
        pairs.sort(key=lambda x: x[1])
        ans = 0
        b = -1e9
        for c, d in pairs:
            if b < c:
                b = d
                ans += 1
        return ans