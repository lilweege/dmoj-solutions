from bisect import bisect
import sys
input = sys.stdin.readline
t = int(input())
tree = [0]*(t+1)

def update(n):
	while n <= t:
		tree[n] += 1
		n += n & -n

def query(n):
	update(n+1)
	tot = 0
	while n > 0:
		tot += tree[n]
		n -= n & -n
	return tot

arr = [int(input()) for _ in range(t)]
arr = [bisect(sorted(arr), arr[i])+1 for i in range(t)]
ans = sum(query(arr[i]-1) for i in reversed(range(t)))
print("{:.2f}".format((ans+t)/t))
