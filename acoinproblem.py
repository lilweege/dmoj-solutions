import sys
input = sys.stdin.readline
MAXN = 10000

n, v = map(int, input().split())

coins = [0] + list(map(int, input().split()))
dp = [0] + [float('inf') for _ in range(MAXN)]

stores = sorted([(j, ) + tuple(map(int, input().split())) for j in range(v)], key = lambda t: t[2])
res = [float('inf') for _ in range(v)]

I = 0
for i in range(1, n+1):
	for j in range(coins[i], MAXN+1):
		dp[j] = min(dp[j], dp[j - coins[i]] + 1)

	while I != v:
		j, l, c = stores[I]
		if c != i:
			break
		res[j] = dp[l]
		I += 1


for r in res:
	print("-1" if r == float('inf') else r)
