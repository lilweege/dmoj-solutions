class Edge:
	def __init__(self, u, v, w):
		self.u = u
		self.v = v
		self.w = w

	def __lt__(self, other):
		return self.w < other.w

	def __iter__(self):
		yield from (self.u, self.v, self.w,)

	def __repr__(self):
		return f"({self.u}, {self.v}, {self.w})"

# max flow min cut is cool
class Network:
	def __init__(self, n, src, snk):
		self.n = n
		self.src = src
		self.snk = snk
		self.last = [-1]*n
		self.edges = []

	def addEdge(self, x, y, xy, yx):
		n = len(self.edges)
		self.edges.append(Edge(y, self.last[x], xy))
		self.last[x] = n
		self.edges.append(Edge(x, self.last[y], yx))
		self.last[y] = n+1

	def dfs(self, cur, flow):
		self.visit.add(cur)
		if cur == self.snk:
			return flow

		i = self.last[cur]
		while True:
			if i == -1:
				break

			u, v, w = self.edges[i]
			if w > 0 and u not in self.visit:
				res = self.dfs(u, min(flow, w))
				if res > 0:
					self.edges[i].w -= res
					self.edges[i ^ 1].w += res
					return res
			i = v
		return 0

	def minCut(self):
		res = 0
		while True:
			self.visit = set()
			cur = self.dfs(self.src, float('inf'))
			if cur == 0:
				break
			res += cur
		return res

import sys
input = sys.stdin.readline
n = int(input())

flow = Network(2*n-1, 0, 2*n-2)

for i in range(1, n):
	e = int(input())
	flow.addEdge(2*i-2, 2*i-1, e, 0)

m = int(input())
for i in range(m):
	i, j = map(int, input().split())
	flow.addEdge(2*i-1, 2*j-2, float('inf'), 0)

print(flow.minCut())


'''
6
100
2
7
2
2
9
1 2
2 4
2 5
1 3
4 5
5 3
3 6
4 6
5 6
''' # 9

'''
4
3
2
3
4
1 2
1 3
2 4
3 4
''' # 3
