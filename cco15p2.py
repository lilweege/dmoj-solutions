import sys
input = sys.stdin.readline
n, m = map(int, input().split())
dp = [[-1 for _ in range(1 << n)] for _ in range(n)]
mat = [[0 for _ in range(18)] for _ in range(18)]

for _ in range(m):
	s, d, l = map(int, input().split())
	mat[s][d] = l


def solve(u, mask):
	if u == n - 1:
		dp[u][mask] = 0
	elif dp[u][mask] == -1:
		ret = -sys.maxsize
		for v in range(n):
			if not mask & (1 << v) and mat[u][v] > 0:
				ret = max(ret, mat[u][v] + solve(v, mask | (1 << v)))

		dp[u][mask] = ret

	return dp[u][mask]

print(solve(0, 1))
