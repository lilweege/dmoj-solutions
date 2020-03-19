n = int(input())

t = input().split()
swifts = [int(t[i]) for i in range(n)]

t = input().split()
semaphores = [int(t[i]) for i in range(n)]

best = 0
sumOne = 0
sumTwo = 0
for k in range(n):
	sumOne += swifts[k]
	sumTwo += semaphores[k]
	if sumOne == sumTwo:
		best = k+1

print(best)