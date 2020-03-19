n = int(input())
grid = []
for i in range(n):
	t = input().split()
	row = []
	for j in t:
		row.append(int(j))
	grid.append(row)

while True:
	correct = True
	for row in grid:
		if sorted(row) != row:
			correct = False
			break
	if correct:
		prev = 0
		for i in range(len(grid)):
			if grid[i][0] > prev:
				prev = grid[i][0]
			else:
				correct = False
				break
		
	if correct:
		break
	else:
		# rotate the grid
		for i in range(0, int(n/2)):
			for j in range(i, n-i-1):
				t = grid[i][j]
				grid[i][j] = grid[j][n-1-i]
				grid[j][n-1-i] = grid[n-1-i][n-1-j]
				grid[n-1-i][n-1-j] = grid[n-1-j][i]
				grid[n-1-j][i] = t

for i in range(n):
	for j in range(n):
		print(grid[i][j], end = ' ')
	print("")