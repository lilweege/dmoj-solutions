INF = 10**9

import heapq
import sys
input = sys.stdin.readline
m = int(input())

verts = []
for _ in range(m):
	pen = {}
	line = list(map(int, input().split(" ")))
	edges = line[0]
	pens = []
	for i in range(1, edges+1):
		cost = line[i+edges]
		if i == edges:
			if line[i] > line[1]:
				vert = line[1], line[i]
			else:
				vert = line[i], line[1]
		else:
			if line[i+1] > line[i]:
				vert = line[i], line[i+1]
			else:
				vert = line[i+1], line[i]

		pen[vert] = cost
	verts.append(pen)


pens = {}
for i in range(m+1):
	pens[i] = {}

for i in range(m):
	for edge in verts[i].keys():
		for j in range(i+1, m):
			if edge in verts[j]:
				if i in pens[j]:
					if pens[j][i] > verts[j][edge]:
						pens[i][j] = verts[j][edge]
						pens[j][i] = verts[j][edge]
					else:
						pens[i][j] = pens[j][i]
						pens[j][i] = pens[j][i]
				else:
					pens[i][j] = verts[j][edge]
					pens[j][i] = verts[j][edge]

				del verts[j][edge]
				break
		else:
			if i in pens[m]:
				if pens[m][i] > verts[i][edge]:
					pens[i][m] = verts[i][edge]
					pens[m][i] = verts[i][edge]
				else:
					pens[i][m] = pens[m][i]
					pens[m][i] = pens[m][i]
			else:
				pens[i][m] = verts[i][edge]
				pens[m][i] = verts[i][edge]



def prim(graph):
	tree = {}

	start = 0
	visited = {start}

	pq = [(cost, start, nex) for nex, cost in graph[start].items()]
	heapq.heapify(pq)

	while pq:
		cost, prev, cur = heapq.heappop(pq)

		if cur not in visited:
			visited.add(cur)

			tree.setdefault(prev, {})[cur] = cost

			for nex, cost in graph[cur].items():
				if nex not in visited:
					heapq.heappush(pq, (cost, cur, nex))

	return None if len(visited) < len(graph) else tree



withOutside = 0
paths = prim(pens)
if paths:
	for path in paths.values():
		for cost in path.values():
			withOutside += cost
else:
	withOutside = INF


for pen in pens.values():
	if m in pen:
		del pen[m]
del pens[m]


withoutOutside = 0
paths = prim(pens)
if paths:
	for path in paths.values():
		for cost in path.values():
			withoutOutside += cost
else:
	withoutOutside = INF


print(min(withOutside, withoutOutside))
