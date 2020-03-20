# python solution too slow

def segmentedSieveCount(n, m):
	cnt = 0
	lim = int(m**0.5)+1
	prime = []
	mark = [True] * (lim+1)
	p = 2
	while (p * p <= lim):
		if (mark[p] == True):
			for i in range(p * p, lim + 1, p):
				mark[i] = False
		p += 1

	for p in range(2, lim):
		if mark[p]:
			prime.append(p)
			if p > n:
				cnt += 1

	low = lim
	high = lim * 2
	while low < m:
		if high >= m:
			high = m

		mark = [True] * (lim+1)

		for i in range(len(prime)):
			loLim = low // prime[i] * prime[i]
			if loLim < low:
				loLim += prime[i]

			for j in range(loLim, high, prime[i]):
				mark[j - low] = False

		for i in range(low, high):
			if mark[i - low] and i > n:
				cnt += 1

		low += lim
		high += lim

	return cnt

import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
print(segmentedSieveCount(n, m))
