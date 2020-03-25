grid = [input().split(),
		input().split(),
		input().split()]

for y in range(3):
	for x in range(3):
		if grid[y][x] != "X":
			grid[y][x] = int(grid[y][x])


# so far only checking when one X in row or col
for y in range(3):
	vars = grid[y].count("X")
	if vars == 1:
		if grid[y][0] == "X":
			grid[y][0] = 2 * grid[y][1] - grid[y][2]
		if grid[y][1] == "X":
			grid[y][1] = (grid[y][0] + grid[y][2]) / 2
		if grid[y][2] == "X":
			grid[y][2] = 2 * grid[y][1] - grid[y][0]		
	for x in range(3):
		col = [grid[0][x], grid[1][x], grid[2][x]]
		vars = col.count("X")
		if vars == 1:
			if col[0] == "X":
				grid[0][x] = 2 * col[1] - col[2]
			if col[1] == "X":
				grid[1][x] = (col[0] + col[2]) / 2
			if col[2] == "X":
				grid[2][x] = 2 * col[1] - col[0]
for y in range(3):
	vars = grid[y].count("X")
	if vars == 1:
		if grid[y][0] == "X":
			grid[y][0] = 2 * grid[y][1] - grid[y][2]
		if grid[y][1] == "X":
			grid[y][1] = (grid[y][0] + grid[y][2]) / 2
		if grid[y][2] == "X":
			grid[y][2] = 2 * grid[y][1] - grid[y][0]

for y in range(3):
	vars = grid[y].count("X")
	if vars == 0:
		if y == 0:
			if  grid[1][0] == "X" and grid[1][1] == "X" and grid[1][2] == "X"\
			and grid[2][0] == "X" and grid[2][1] == "X" and grid[2][2] == "X":
				grid[1][0] = grid[0][0]
				grid[2][0] = grid[0][0]
				grid[1][1] = grid[0][1]
				grid[2][1] = grid[0][1]
				grid[1][2] = grid[0][2]
				grid[2][2] = grid[0][2]
	if vars == 0:
		if y == 1:
			if  grid[0][0] == "X" and grid[0][1] == "X" and grid[0][2] == "X"\
			and grid[2][0] == "X" and grid[2][1] == "X" and grid[2][2] == "X":
				grid[0][0] = grid[1][0]
				grid[2][0] = grid[1][0]
				grid[0][1] = grid[1][1]
				grid[2][1] = grid[1][1]
				grid[0][2] = grid[1][2]
				grid[2][2] = grid[1][2]
	if vars == 0:
		if y == 2:
			if  grid[1][0] == "X" and grid[1][1] == "X" and grid[1][2] == "X"\
			and grid[0][0] == "X" and grid[0][1] == "X" and grid[0][2] == "X":
				grid[1][0] = grid[2][0]
				grid[0][0] = grid[2][0]
				grid[1][1] = grid[2][1]
				grid[0][1] = grid[2][1]
				grid[1][2] = grid[2][2]
				grid[0][2] = grid[2][2]

for x in range(3):
	col = [grid[0][x], grid[1][x], grid[2][x]]
	vars = col.count("X")
	if vars == 0:
		if x == 0:
			if  grid[0][1] == "X" and grid[1][1] == "X" and grid[2][1] == "X"\
			and grid[0][2] == "X" and grid[1][2] == "X" and grid[2][2] == "X":
				grid[0][1] = grid[0][0]
				grid[0][2] = grid[0][0]
				grid[1][1] = grid[1][0]
				grid[1][2] = grid[1][0]
				grid[2][1] = grid[2][0]
				grid[2][2] = grid[2][0]
	if vars == 0:
		if x == 1:
			if  grid[0][0] == "X" and grid[1][0] == "X" and grid[2][0] == "X"\
			and grid[0][2] == "X" and grid[1][2] == "X" and grid[2][2] == "X":
				grid[0][0] = grid[0][1]
				grid[0][2] = grid[0][1]
				grid[1][0] = grid[1][1]
				grid[1][2] = grid[1][1]
				grid[2][0] = grid[2][1]
				grid[2][2] = grid[2][1]
	if vars == 0:
		if x == 2:
			if  grid[0][1] == "X" and grid[1][1] == "X" and grid[2][1] == "X"\
			and grid[0][0] == "X" and grid[1][0] == "X" and grid[2][0] == "X":
				grid[0][1] = grid[0][2]
				grid[0][0] = grid[0][2]
				grid[1][1] = grid[1][2]
				grid[1][0] = grid[1][2]
				grid[2][1] = grid[2][2]
				grid[2][0] = grid[2][2]



for y in range(3):
	for x in range(3):
		if grid[y][x] != "X":
			grid[y][x] = int(grid[y][x])

for r in grid:
	print(r[0], r[1], r[2])