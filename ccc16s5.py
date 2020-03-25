import math
import sys
input = sys.stdin.readline

n, t = map(int,input().split())
cur = [bool(int(b)) for b in input()[:-1]]

pmod = lambda x: ((x%n)+n)%n

b = 1
while t > 0:
	if t%2 != 0:
		nex = [False]*n
		for i in range(n):
			if cur[i]:
				r = pmod(i+b)
				l = pmod(i-b)
				nex[r] = not nex[r]
				nex[l] = not nex[l]
		cur = nex
	t //= 2
	b <<= 1

print(''.join(str(int(b)) for b in cur))
