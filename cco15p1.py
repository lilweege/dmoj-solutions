import sys
input = sys.stdin.readline

n, w = map(int, input().split())
temp = sorted([int(input()) for _ in range(n)])
minTaste = abs(w - temp[0]) + abs(w - temp[-1]) if w > temp[0] and w < temp[-1] else min(abs(w - temp[0]), abs(w - temp[-1])) + (temp[-1] - temp[0])


l = 1
r = n - 1
maxTaste1 = abs(w - temp[0])
for i in range(n-1):
	if i % 2 == 0:
		maxTaste1 += max(abs(w - temp[r]), temp[r] - temp[l-1])
		r -= 1
	else:
		maxTaste1 += max(abs(w - temp[l]), temp[r+1] - temp[l])
		l += 1

l = 0
r = n - 2
maxTaste2 = abs(w - temp[-1])
for i in range(n-1):
	if i % 2 == 0:
		maxTaste2 += max(abs(w - temp[l]), temp[r+1] - temp[l])
		l += 1
	else:
		maxTaste2 += max(abs(w - temp[r]), temp[r] - temp[l-1])
		r -= 1

print(minTaste, max(maxTaste1, maxTaste2))
