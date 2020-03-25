import sys
input = sys.stdin.readline

cnt = {1: 1}
def getTrees(n):
	if n in cnt:
		return cnt[n]

	sum = 0
	for i in range(2, n+1):
		w = n//i
		sum += getTrees(w)

	cnt[n] = sum
	return sum

print(getTrees(int(input())))
