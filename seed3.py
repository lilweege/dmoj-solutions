import sys
input = sys.stdin.readline

i = int(input())
n = int(input())
j = int(input())

a = [0]*(i+2)
for _ in range(j):
	xi, xf, k = map(int, input().split())
	a[xi] += k
	a[xf+1] -= k

cnt = 0
for x in range(1, i+1):
	a[x] += a[x-1]
	if a[x] < n:
		cnt += 1

print(cnt)
