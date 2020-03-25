import sys
n = int(sys.stdin.readline())

friends = [int(sys.stdin.readline()) for _ in range(n-1)]
ways = [1 for _ in range(n+1)]

for i in range(n-1):
	ways[friends[i]] += ways[friends[i]] * ways[i+1]

print(ways[-1])