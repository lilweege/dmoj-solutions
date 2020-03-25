import sys
input = sys.stdin.readline

def createSieve(n):
	if n <= 0:
		return None

	sieve = [i > 1 for i in range(n+1)]
	for i in range(2, int(n**0.5)+1):
		if sieve[i]:
			for j in range(i*i, n+1, i):
				sieve[j] = False

	return sieve


n = int(input())
maxb = 0
cases = []
for _ in range(n):
	a, b = map(int, input().split())
	maxb = max(maxb, b)
	cases.append((a, b))

s = createSieve(maxb)
for a, b in cases:
	print(s[a:b].count(True))
