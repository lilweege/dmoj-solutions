def createSieve(n):
	if n <= 0:
		return [], []

	primes = []
	sieve = [i > 1 for i in range(n+1)]
	for i in range(2, n+1):
		if sieve[i]:
			primes.append(i)
			for j in range(i*i, n+1, i):
				sieve[j] = False

	return sieve, primes

n = int(input())
m = int(input())
sieve, primes = createSieve(n)
costs = [int(input()) for _ in range(m)]
total = 2*sum(costs)
vis = [i == total for i in range(n+1)]

pt = False
for spent in range(total, n+1):
	if vis[spent]:
		if sieve[spent]:
			pt = True
			break

		for cost in costs:
			for prime in primes:
				nSpent = cost * prime + spent
				if nSpent > n:
					break
				vis[nSpent] = True

print("its primetime" if pt\
 else "not primetime")
