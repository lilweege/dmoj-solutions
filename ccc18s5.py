import sys
input = sys.stdin.readline
#f = open("./s5/s5.4-05.in")

max = 10**5
class Edge:
	def __init__(self, a, b, c, d):
		self.a = a
		self.b = b
		self.c = c
		self.d = d

	def __lt__(self, other):
		return self.c < other.c

totalCost = minCost = cnt0 = cnt1 = 0

#n, m, p, q = map(int, f.readline().split())
n, m, p, q = map(int, input().split())
par0 = [x for x in range(n+1)]
par1 = [x for x in range(m+1)]
# rnk0 = [0]*(n+1)
# rnk1 = [0]*(m+1)

edges = []
def find0(n):
	if par0[n] == n:
		return n
	par0[n] = find0(par0[n])
	return par0[n]

# def merge0(a, b):
# 	a = find0(a)
# 	b = find0(b)
# 	if a == b:
# 		return False
# 	if rnk0[a] > rnk0[b]:
# 		par0[b] = a
# 	else:
# 		par0[a] = b
#
# 	if rnk0[a] == rnk0[b]:
# 		rnk0[b] += 1
# 	return True

def find1(n):
	if par1[n] == n:
		return n
	par1[n] = find1(par1[n])
	return par1[n]

# def merge1(a, b):
# 	a = find1(a)
# 	b = find1(b)
# 	if a == b:
# 		return False
# 	if rnk1[a] > rnk1[b]:
# 		par1[b] = a
# 	else:
# 		par1[a] = b
#
# 	if rnk1[a] == rnk1[b]:
# 		rnk1[b] += 1
# 	return True


for i in range(p):
#	a, b, c = map(int, f.readline().split())
	a, b, c = map(int, input().split())
	edges.append(Edge(a, b, c, 0))
	totalCost += n*c

for j in range(q):
#	x, y, z = map(int, f.readline().split())
	x, y, z = map(int, input().split())
	edges.append(Edge(x, y, z, 1))
	totalCost += m*z



edges.sort()

# for edge in edges:
# 	if edge.d == 0:
# 		if merge1(edge.a, edge.b):
# 			cnt0 += 1
# 			minCost += (n-cnt1) * edge.c
# 	else:
# 		if merge0(edge.a, edge.b):
# 			cnt1 += 1
# 			minCost += (m-cnt0) * edge.c


for edge in edges:
	if edge.d == 0:
		if cnt0 != m-1 and find1(edge.a) != find1(edge.b):
			par1[find1(edge.a)] = find1(edge.b)
			minCost += edge.c * (n-cnt1)
			cnt0 += 1

	else:
		if cnt1 != n-1 and find0(edge.a) != find0(edge.b):
			par0[find0(edge.a)] = find0(edge.b)
			minCost += edge.c * (m-cnt0)
			cnt1 += 1

print(totalCost - minCost)
