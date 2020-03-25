import sys
input = sys.stdin.readline
n = int(input())

adj = [[] for i in range(n+1)]
dist = [0]*n
poss = [1]*n

for i in range(n - 1):
	i, j = map(lambda x: int(x) - 1, input().split())
	adj[i].append(j)
	adj[j].append(i)

leng = 0
ways = 0
def dfs(cur, prev):
	global leng
	global ways
	if cur != prev and len(adj[cur]) == 0:
		return 0

	for nex in adj[cur]:
		if nex != prev:
			d = dfs(nex, cur) + 1
			if d + dist[cur] > leng:
				leng = d + dist[cur]
				ways = poss[nex] * poss[cur]
			elif d + dist[cur] == leng:
				ways += poss[nex] * poss[cur]

			if d > dist[cur]:
				dist[cur] = d
				poss[cur] = poss[nex]
			elif d == dist[cur]:
				poss[cur] += poss[nex]
	return dist[cur]

dfs(1, 1)
print(leng + 1, ways)
