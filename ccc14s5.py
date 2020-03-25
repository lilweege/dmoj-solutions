import sys
n = int(sys.stdin.readline())

best, prev, dist = [], [], []
for _ in range(n+1):
	best.append(0)
	prev.append(0)
	dist.append(0)


points = [(0, 0)] + [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

def euclidianDist(a, b):
	return ((a[0]-b[0])**2 + (a[1]-b[1])**2)**0.5

for cost, a, b in sorted([(euclidianDist(points[fr], points[to]), fr, to) for fr in range(n+1) for to in range(fr+1, n+1)], key=lambda x: x[0]):

	if dist[a] != cost:
		prev[a] = best[a]
		dist[a] = cost
	if dist[b] != cost:
		prev[b] = best[b]
		dist[b] = cost

	if a == 0:
		best[a] = max(best[a], prev[b])
	else:
		best[a] = max(best[a], prev[b]+1)
		best[b] = max(best[b], prev[a]+1)

print(best[0] + 1)
