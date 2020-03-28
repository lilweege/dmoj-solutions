import sys
input = sys.stdin.readline

n = int(input())
adj1 = [[] for _ in range(n)]
adj2 = [[] for _ in range(n)]
ans = [int(i == 0) for i in range(n)]

while True:
	x, y = map(lambda v: int(v)-1, input().split())
	if x == -1 and y == -1:
		break
	adj1[x].append(y)
	adj2[y].append(x)

q = [0]
while q:
	u = q.pop(0)
	for v in adj1[u]:
		ans[v] += ans[u]
		adj2[v].remove(u)
		if v != n-1 and len(adj2[v]) == 0:
			q.append(v)

print(ans[n-1])
