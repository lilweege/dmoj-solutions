class Edge:
	def __init__(self, a, b, c):
		self.a = a
		self.b = b
		self.c = c

	def __lt__(self, other):
		return self.c < other.c

	def __iter__(self):
		yield from (self.a, self.b, self.c,)

	def __repr__(self):
		return f"Edge({self.a}, {self.b}, {self.c})"

def kruskal(graph, isSorted = False):
	n = len(graph)
	parent = list(range(n))
	rank = [0]*n

	def find(n):
		if parent[n] != n:
			parent[n] = find(parent[n])
		return parent[n]

	def union(x, y):
		xroot = find(x)
		yroot = find(y)
		if rank[xroot] < rank[yroot]:
			parent[xroot] = yroot
		elif rank[xroot] > rank[yroot]:
			parent[yroot] = xroot
		else:
			parent[yroot] = xroot
			rank[xroot] += 1

	mst = []
	cost = 0
	for edge in graph if isSorted else sorted(graph):
		u, v, w = edge
		x = find(u)
		y = find(v)

		if x != y:
			mst.append(edge)
			cost += w
			union(x, y)

	# return cost
	# return mst
	return {cost: mst}

'''
5
2 3 5
3 2 7
1 2 6
1 1 8
2 1 5
'''

print(kruskal([Edge(*map(int, input().split())) for _ in range(int(input()))]))
