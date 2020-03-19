import sys
import math
import heapq

# hull is k centimetres thick
# there are n islands
# there are m sea paths
k, n, m = map(int, input().split())

# visited islands
visited = [[False for _ in range(201)] for _ in range(n)]
# distance will be infinity if cannot be reached
distance = [[float("inf") for _ in range(201)] for _ in range(n)]

# adjacent, or edges between nodes
paths = [{} for _ in range(n)]
for _ in range(m):
	# starting from island a [index]
	# and going to island b [dict key]
	# will take (t, h) time (mins) and hull (integrity) [dict value]
	a, b, t, h = map(int, input().split())
	a, b = a-1, b-1

	# can go in both directions between islands
	paths[a].setdefault(b, []).append((t, h))
	paths[b].setdefault(a, []).append((t, h))

# a is starting island
# b is target island
a, b = map(int, input().split())
a, b = a-1, b-1

# distance from start to start is 0
distance[a][k] = 0


def getChildren(a, h):
	children = []

	# d is destination island (b is already taken)
	for d in paths[a]:
		for route in paths[a][d]:
			# new a(start island) and h(hull integrity) values
			na = distance[a][h] + route[0]
			nh = h - route[1]
			child = (na, d, nh)

			# hull is still in tact
			if nh > 0:
				children.append(child)
				# better distance
				if na < distance[d][nh]:
					distance[d][nh] = na
	return children


q = [(0, a, k)]
time = -1
while q:
	island = heapq.heappop(q)
	t, a, h = island

	if a == b:
		time = t
		break
	if visited[a][h]:
		continue
	visited[a][h] = True

	for child in getChildren(a, h):
		heapq.heappush(q, child)

print(time)
