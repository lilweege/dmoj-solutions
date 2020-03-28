import sys
input = sys.stdin.readline

for _ in range(int(input())):
	n = int(input())
	X = list(map(int, input().split()))
	Y = list(map(int, input().split()))

	best = 0
	for i in range(n):
		for j in range(i, n):
			if X[i] <= Y[j]:
				best = max(best, j - i)

	print(f"The maximum distance is {best}")
