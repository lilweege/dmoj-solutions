'''
def EdmondsKarp(adj, cap, src, snk):
	n = len(cap)
	flow = 0
	F = [[0 for y in range(n)] for x in range(n)]
	while True:
		P, P[src] = [-1]*n, -2
		M, M[src] = [0]*n, float('inf')
		pathFlow, P = bfs(adj, cap, src, snk, F, P, M)
		if pathFlow == 0:
			break
		flow += pathFlow

		v = snk
		while v != src:
			u = P[v]
			F[u][v] += pathFlow
			F[v][u] -= pathFlow
			v = u
	return flow

def bfs(adj, cap, src, snk, F, P, M):
	q = [src]
	while q:
		u = q.pop(0)
		for v in adj[u]:
			if cap[u][v] - F[u][v] > 0 and P[v] == -1:
				P[v] = u
				M[v] = min(M[u], cap[u][v] - F[u][v])
				if v == snk:
					return M[snk], P
				q.append(v)
	return 0, P
'''
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

print(flow.edges)
print(flow.minCut())

# maxn = 202
# last = [-1]*(2*n+2)
# edges = []
# for i in range(1, n):
# 	e = int(input())
# 	x, y, xy, yx = 2*i-2, 2*i-1, e, 0
# 	n = len(edges)
# 	edges.append((y, last[x], xy))
# 	last[x] = n
# 	edges.append((x, last[y], yx))
# 	last[y] = n+1
#
# m = int(input())
# for i in range(m):
# 	i, j = map(int, input().split())
# 	x, y, xy, yx = 2*i-1, 2*j-2, float('inf'), 0
# 	n = len(edges)
# 	edges.append((y, last[x], xy))
# 	last[x] = n
# 	edges.append((x, last[y], yx))
# 	last[y] = n+1
#
# # print(edges)
# E = [[] for _ in range(2*n+2)]
# C = [[0 for _ in range(maxn)] for _ in range(maxn)]
# for u, v, w in edges:
# 	# print(u, v, w)
# 	C[u][v] = w
# 	E[u].append(v)
# # print(E)
#
# for i in range(-1, 3):
# 	for j in range(2*n-4, 2*n+5):
# 		a = (EdmondsKarp(E, C, i, j))
# 		if a != 0:
# 			print(f"{i}, {j} => {a}")


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
''' # 9 not 11

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

'''
energy = [0] + [int(input()) for _ in range(n-1)] + [0]

energy = [0]*(n+1)
for i in range(1, n):
	energy[i] = int(input())


m = int(input())
E = [{} for _ in range(n+1)]
for i in range(m):
	i, j = map(int, input().split())
	E[i].setdefault(j)
for i, e in enumerate(energy):
	for key in E[i].keys():
		E[i][key] = e


m = int(input())
E = [[] for _ in range(n+1)]
for i in range(m):
	i, j = map(int, input().split())
	E[i].append(j)




C = [[INF for _ in range(n+1)] for _ in range(n+1)]
for i, nodes in enumerate(E):
	for node in nodes:
		C[i][node] = energy[i]


s = 1
t = n
print(EdmondsKarp(E, C, s, t))

'''
