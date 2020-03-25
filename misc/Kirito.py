# MLE LOL

'''
5 8
01000100
01000100
00100111
00100110
00100000
4
1 2
3 5
3 4
2 2
'''

M = 5000 + 1
N = 2000
Q = 50000 + 1

class Node:
	v = 0
	def __init__(self, l = 0, r = 0):
		self.l = l
		self.r = r


primeSeed = 101
class Hash:
	hashv = [0]*M
	def __init__(self, s):
		self.hashv = [0]*M
		for i, c in enumerate(s):
			self.hashv[i+1] = self.hashv[i] * primeSeed + ord(c)

	def getHash(self, i):
		return self.hashv[i]


def midp(l, r):
	return l + (r - l) // 2


def LCP(a, b):
	l = 0
	r = m + 1
	while l < r:
		mid = midp(l, r)
		if a.getHash(mid) == b.getHash(mid):
			l = mid + 1
		else:
			r = mid
	return r - 1


seg = [None for i in range(Q)]
def build(l, r, i):
	seg[i] = Node(l, r)
	if l == r:
		seg[i].v = m
		return
	mid = midp(l, r)
	build(l, mid, 2*i)
	build(mid+1, r, 2*i+1)
	seg[i].v = min(min(seg[2*i].v, seg[2*i+1].v), lcp[ids[mid]][ids[mid+1]])


def update(p, i):
	if seg[i].l != p or seg[i].r != p:
		mid = midp(seg[i].l, seg[i].r)
		update(p, 2*i + (p>mid))
		seg[i].v = min(min(seg[2*i].v, seg[2*i+1].v), lcp[ids[mid]][ids[mid+1]])


def query(l, r, i):
	if seg[i].l == l and seg[i].r == r:
		return seg[i].v

	mid = midp(seg[i].l, seg[i].r)
	if l > mid:
		return query(l, r, 2*i+1)
	if r <= mid:
		return query(l, r, 2*i)
	return min(min(query(l, mid, 2*i), query(mid+1, r, 2*i+1)), lcp[ids[mid]][ids[mid+1]])


import sys
input = sys.stdin.readline
n, m = map(int, input().split())
ids = list(range(n+1)) + [0]*(N-n)
hashes = [None] + [Hash(input()[:-1]) for i in range(1, n+1)]
# lcp = [[LCP(hashes[i], hashes[j]) if 1 <= i <= n else 0 for i in range(N+1)] if 1 <= j <= n else [0 for i in range(N+1)] for j in range(N+1)]
lcp = [[0 for i in range(N+1)] for i in range(N+1)]
for i in range(1, n+1):
	for j in range(1, n+1):
		lcp[i][j] = LCP(hashes[i], hashes[j])

def main():
	build(1, n, 1)
	q = int(input())
	for _ in range(q):
		i, j = map(int, input().split())
		print((j - i + 1) * query(i, j, 1))
		ids[i], ids[j] = ids[j], ids[i]
		update(i, 1)
		update(j, 1)

if __name__ == '__main__':
	main()
