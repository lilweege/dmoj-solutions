def getDistances(start):
	def travel(cur, prev, level):
		global dist
		dist[cur] = level
		for nex in paths[cur]:
			if nex != prev and nex in visited:
				travel(nex, cur, level+1)

	travel(start, -1, 0)


def visit(start):
	def travel(cur, prev):
		global total

		if cur in pho:
			visited[cur] = True

		for nex in paths[cur]:
			if nex != prev:
				travel(nex, cur)
				if nex in visited:
					visited[cur] = True
					total += 2

	travel(start, -1)


n, m = map(int, input().split(" "))
pho = {i: True for i in map(int, input().split(" "))}

paths = {i: [] for i in range(n)}
for path in range(n-1):
	a, b = map(int, input().split(" "))
	paths[a].append(b)
	paths[b].append(a)

visited = {}
total = 0
visit(next(iter(pho)))

dist = [0 for _ in range(n)]
getDistances(next(iter(visited)))

maxInd = dict(zip(dist, range(n)))[max(dist)]

dist = [0 for _ in range(n)]
getDistances(maxInd)

print(total - max(dist))
