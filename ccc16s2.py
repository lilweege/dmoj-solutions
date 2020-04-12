t = int(input())
n = int(input())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())), reverse = (t == 2))

tot = 0
for i in range(n):
	tot += max(a[i], b[i])

print(tot)
