class Edge:
	def __init__(self, a, b, c, o):
		self.a = a
		self.b = b
		self.c = c
		self.o = o

	def __lt__(self, other):
		return self.c < other.c

	def __iter__(self):
		yield from [self.a, self.b, self.c, self.o]

	def __repr__(self):
		return f"Edge({self.a}, {self.b}, {self.c}, {self.o})"


def find(n):
	if parent[n] != n:
		parent[n] = find(parent[n])
	return parent[n]

def merge(a, b):
	xroot = find(a)
	yroot = find(b)
	if xroot == yroot:
		return False
	if rank[xroot] > rank[yroot]:
		parent[yroot] = xroot
	else:
		parent[xroot] = yroot

	if rank[xroot] == rank[yroot]:
		rank[yroot] += 1
	return True

import sys
input = sys.stdin.readline
n, m, d = map(int, input().split())
parent = list(range(n+1))
rank = [0]*(n+1)
edges = sorted([Edge(*map(int, input().split()), i+1 < n) for i in range(m)])

cnt = 0
mi = 0
days = 0

for u, v, w, o in edges:
	if merge(u, v):
		cnt += 1
		mi = w
		days += not o
		if cnt == n-1:
			break

parent = list(range(n+1))
if not o:
	for u, v, w, o in edges:
		if find(u) != find(v):
			if w < mi or (o and w == mi):
				merge(u, v)
			elif o and w <= d:
				days -= 1
				break

print(days)
