import sys
r, c = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

grid = [[0 for i in range(c)] for j in range(r)]
grid[0][0] = 1

wall = [[False for i in range(c)] for j in range(r)]
for _ in range(k):
	row, col = map(int, sys.stdin.readline().split())
	wall[row-1][col-1] = True
wall[0][0] = True

for i in range(c):
	for j in range(r):
		if not wall[j][i]:
			grid[j][i] = grid[j-1][i] + grid[j][i-1]

print(grid[r-1][c-1])