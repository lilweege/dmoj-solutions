import sys
lim = 10000
n = int(sys.stdin.readline())

friends = [0 for _ in range(lim)]
for _ in range(n):
	i, j = map(int, sys.stdin.readline().split())
	friends[i] = j


res = []
while True:
	x, y = map(int, sys.stdin.readline().split())
	if x == 0 and y == 0:
		break

	separation = -1
	checked = [False for _ in range(lim)]
	
	while not checked[x]:
		if x == y:
			break
		checked[x] = True
		x = friends[x]
		separation += 1
	
	res.append("Yes " + str(separation) if x == y else "No")

for r in res:
	print(r)